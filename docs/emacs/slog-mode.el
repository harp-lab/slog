;;; slog-mode.el --- Major mode for the Slog language -*- lexical-binding: t; -*-

;; Author: (generated for the Slog compiler)
;; Keywords: languages, datalog, logic
;; Version: 0.1

;;; Commentary:

;; A first-cut major mode for editing `.slog' files -- the Slog Datalog-ish
;; deductive language whose surface syntax is fully s-expression based
;; (see compiler/lexer.rkt and compiler/parser.rkt).
;;
;; Features:
;;   * Syntax highlighting for top-level keywords, declared struct / table /
;;     union / enum / lattice / demand / extern names, primitive functions,
;;     built-in types, operators/arrows, constants, refs and comments.  Every
;;     category is its own `defface' (see the `slog-*-face' definitions below)
;;     so the colours are trivially re-styled via `M-x customize-group RET
;;     slog RET' or a `set-face-attribute' in your init file.
;;   * S-expression aware indentation: arguments line up under the first
;;     argument of their form (the style used throughout lib/*.slog), rule
;;     bodies align to the clause above, and top-level forms sit at column 0.
;;   * Indentation NEVER inserts a literal tab -- TAB always justifies with
;;     spaces (`indent-tabs-mode' is forced nil).
;;   * `imenu' entries for every declaration.
;;   * Documentation at point (eldoc): resting the cursor on any token
;;     silently shows a 2-3 line note in the echo area.  Built-in language
;;     features (struct, +, demand, ...) are documented by the declarative
;;     table `slog-builtin-docs' below -- edit that table to change or extend
;;     the docs.  User-defined names show their own defining source lines:
;;     the declaration plus deriving rule heads, found in this file and in
;;     files reachable through `include'/`run'.  `C-c C-d' shows the same
;;     note on demand; `slog-doc-enable' turns the feature off.
;;
;; Installation:
;;   1.  mv slog-mode.el ~/.emacs.d/lisp/        (or any directory on your
;;                                                `load-path')
;;   2.  Add to your init file (~/.emacs or ~/.emacs.d/init.el):
;;
;;         (add-to-list 'load-path "~/.emacs.d/lisp/")
;;         (require 'slog-mode)
;;
;;       or, to load lazily:
;;
;;         (add-to-list 'load-path "~/.emacs.d/lisp/")
;;         (autoload 'slog-mode "slog-mode" "Major mode for Slog." t)
;;         (add-to-list 'auto-mode-alist '("\\.slog\\'" . slog-mode))
;;
;;   The `require' form already registers the `.slog' auto-mode association,
;;   so with `require' you do not need the `add-to-list' line yourself.

;;; Code:

(require 'cl-lib)

;;;; ------------------------------------------------------------------ ;;;;
;;;; Customization group + knobs
;;;; ------------------------------------------------------------------ ;;;;

(defgroup slog nil
  "Major mode for editing Slog source files."
  :group 'languages
  :prefix "slog-")

(defcustom slog-indent-offset 1
  "Number of columns to indent inside a bracketed form that opens at end of line.
This is the offset used for the rare case

    (
     child)

Most indentation lines children up under the first argument of the form and
does not consult this value."
  :type 'integer
  :group 'slog)

(defcustom slog-arrow-offset 1
  "Column at which a line beginning with a rule arrow (`<--' / `-->') is indented.
The Slog libraries write the arrow one space in under the `rule' keyword, e.g.

    rule (head ...)
     <-- (body ...)
"
  :type 'integer
  :group 'slog)

;;;; ------------------------------------------------------------------ ;;;;
;;;; Faces -- one per highlighted category, all customizable
;;;; ------------------------------------------------------------------ ;;;;

(defface slog-keyword-face
  '((t :inherit font-lock-keyword-face))
  "Face for top-level and inline keywords (rule, facts, demand, when, ...)."
  :group 'slog)

(defface slog-arrow-face
  '((t :inherit font-lock-keyword-face :weight bold))
  "Face for rule arrows: `-->', `<--', `<-', `->'."
  :group 'slog)

(defface slog-operator-face
  '((t :inherit font-lock-keyword-face))
  "Face for operators: = /= := + - * / %% ^ & | : ? . ..."
  :group 'slog)

(defface slog-struct-face
  '((t :inherit font-lock-type-face))
  "Face for the name declared by `struct'."
  :group 'slog)

(defface slog-union-face
  '((t :inherit font-lock-type-face))
  "Face for the name declared by `union'."
  :group 'slog)

(defface slog-enum-face
  '((t :inherit font-lock-type-face))
  "Face for the name declared by `enum'."
  :group 'slog)

(defface slog-table-face
  '((t :inherit font-lock-variable-name-face))
  "Face for the name declared by `table'."
  :group 'slog)

(defface slog-lattice-face
  '((t :inherit font-lock-variable-name-face))
  "Face for the name declared by `lattice'."
  :group 'slog)

(defface slog-demand-face
  '((t :inherit font-lock-function-name-face))
  "Face for the name declared by `demand' or `extern'."
  :group 'slog)

(defface slog-relation-face
  '((t :inherit font-lock-function-name-face))
  "Face for a relation / struct constructor used as the head of a clause,
i.e. the first symbol after an opening `('."
  :group 'slog)

(defface slog-primitive-face
  '((t :inherit font-lock-builtin-face))
  "Face for built-in primitive functions (band, cget, sqrt, ...)."
  :group 'slog)

(defface slog-type-face
  '((t :inherit font-lock-type-face))
  "Face for built-in type names (int, float, str, any, list, ...)."
  :group 'slog)

(defface slog-constant-face
  '((t :inherit font-lock-constant-face))
  "Face for constants: true, false, numbers and the wildcard `_'."
  :group 'slog)

(defface slog-ref-face
  '((t :inherit font-lock-string-face))
  "Face for single-quoted ref literals, e.g. \\='foo\\='."
  :group 'slog)

(defface slog-keyword-param-face
  '((t :inherit font-lock-builtin-face))
  "Face for keyword parameters such as #:floor and #:ceiling."
  :group 'slog)

;;;; ------------------------------------------------------------------ ;;;;
;;;; Vocabulary
;;;; ------------------------------------------------------------------ ;;;;

(defconst slog-top-level-keywords
  '("def" "rule" "facts" "table" "struct" "union" "demand" "extern"
    "lattice" "enum" "import" "export" "include" "run" "let")
  "Keywords that begin a top-level form (indented to column 0).")

(defconst slog-all-keywords
  (append slog-top-level-keywords '("as" "when" "lambda"))
  "All words highlighted with `slog-keyword-face'.")

(defconst slog-type-names
  '("int" "float" "str" "any" "bool" "cset" "coll" "list"
    "count" "flat" "set" "map")
  "Built-in type names and lattice element kinds.
`min' and `max' are omitted here on purpose: they are primitive functions
\(highlighted via `slog-primitive-face') and only incidentally name lattice
merge operators.")

(defconst slog-primitive-functions
  '("neg" "abs" "min" "max" "pow"
    "band" "bor" "bxor" "bnot" "shl" "shr"
    "sqrt" "sin" "cos" "tan" "exp" "log" "floor" "ceil" "round"
    "tofloat" "toint"
    "size" "substr"
    "cmap" "cput" "cget" "chas" "cmerge" "cdel" "cdiff" "csize" "cins" "cmem"
    "one" "inf" "cplus" "top")
  "Built-in value-producing primitives (compiler/primitives.rkt).")

;;;; ------------------------------------------------------------------ ;;;;
;;;; Syntax table
;;;; ------------------------------------------------------------------ ;;;;

(defvar slog-mode-syntax-table
  (let ((table (make-syntax-table)))
    ;; Bracketing forms.
    (modify-syntax-entry ?\( "()" table)
    (modify-syntax-entry ?\) ")(" table)
    (modify-syntax-entry ?\[ "(]" table)
    (modify-syntax-entry ?\] ")[" table)
    (modify-syntax-entry ?\{ "(}" table)
    (modify-syntax-entry ?\} "){" table)
    ;; Comments: a ";;" pair starts a line comment, a newline ends it.  A
    ;; lone ";" is punctuation (it is a Slog operator), matching the lexer's
    ;; requirement of a *double* semicolon.
    (modify-syntax-entry ?\; ". 12" table)
    (modify-syntax-entry ?\n ">"    table)
    ;; Strings.
    (modify-syntax-entry ?\" "\""   table)
    (modify-syntax-entry ?\\ "\\"   table)
    ;; Symbol constituents.  Identifiers may contain and end with `'' (prime
    ;; notation: A', edge'), so `'' must NOT be a string delimiter.  `#' and
    ;; `:' are joined so that keyword parameters like `#:floor' scan as one
    ;; symbol.
    (modify-syntax-entry ?_  "_" table)
    (modify-syntax-entry ?'  "_" table)
    (modify-syntax-entry ?#  "_" table)
    (modify-syntax-entry ?:  "_" table)
    ;; The remaining operator characters are punctuation.
    (dolist (c '(?+ ?- ?* ?/ ?% ?^ ?= ?< ?> ?& ?| ?? ?. ?~ ?` ?, ?\\))
      (modify-syntax-entry c "." table))
    table)
  "Syntax table for `slog-mode'.")

;;;; ------------------------------------------------------------------ ;;;;
;;;; Font lock
;;;; ------------------------------------------------------------------ ;;;;

(defconst slog--sym "\\(?:\\sw\\|\\s_\\)+"
  "Regexp fragment matching a Slog symbol (word and symbol constituents).")

(defvar slog-font-lock-keywords
  (let ((decl-name (concat "[ \t]*(\\s-*\\(" slog--sym "\\)")))
    `(
      ;; --- ref literals '...':  only when the opening quote is not the tail
      ;; of a primed identifier (i.e. is preceded by whitespace/bracket/BOL).
      ("\\(?:^\\|[^[:alnum:]_']\\)\\('[^'\n]*'\\)"
       (1 'slog-ref-face))

      ;; --- declared names, tagged by their declaring keyword.
      (,(concat "\\_<struct\\_>"  decl-name)  (1 'slog-struct-face))
      (,(concat "\\_<union\\_>"   decl-name)  (1 'slog-union-face))
      (,(concat "\\_<enum\\_>"    decl-name)  (1 'slog-enum-face))
      (,(concat "\\_<table\\_>"   decl-name)  (1 'slog-table-face))
      (,(concat "\\_<lattice\\_>" decl-name)  (1 'slog-lattice-face))
      (,(concat "\\_<demand\\_>"  decl-name)  (1 'slog-demand-face))
      ;; extern has an oracle name between the keyword and the relation.
      (,(concat "\\_<extern\\_>[ \t]+" slog--sym decl-name)
       (1 'slog-demand-face))

      ;; --- keyword parameters (#:floor, #:ceiling, ...).
      ("#:\\(?:\\sw\\|\\s_\\)+" . 'slog-keyword-param-face)

      ;; --- keywords.
      (,(regexp-opt slog-all-keywords 'symbols) . 'slog-keyword-face)

      ;; --- numeric literals (before operators, so a leading `-' is eaten
      ;; by the number rather than highlighted as the minus operator).
      ("\\(?:^\\|[^[:alnum:]_'.]\\)\\(-?[0-9]+\\(?:\\.[0-9]+\\)?\\)"
       (1 'slog-constant-face))

      ;; --- rule arrows.
      ("-->\\|<--\\|<-\\|->" . 'slog-arrow-face)

      ;; --- other operators (longest alternatives first).
      ("\\.\\.\\.\\|:=\\|/=\\|<=\\|>=\\|[-+*/%^=<>&|:?.]"
       . 'slog-operator-face)

      ;; --- built-in types and primitives.
      (,(regexp-opt slog-type-names 'symbols)         . 'slog-type-face)
      (,(regexp-opt slog-primitive-functions 'symbols) . 'slog-primitive-face)

      ;; --- constants and the wildcard.
      (,(regexp-opt '("true" "false") 'symbols) . 'slog-constant-face)
      ("\\_<_\\_>" . 'slog-constant-face)

      ;; --- generic clause head: the first identifier after an open paren
      ;; that no earlier rule has already coloured.  This lights up relation
      ;; and struct-constructor names in facts, rule bodies and heads.  It is
      ;; LAST and non-overriding, so primitives/keywords/types keep their
      ;; own faces.
      ("(\\s-*\\([a-zA-Z_][a-zA-Z0-9_']*\\)"
       (1 'slog-relation-face nil t))))
  "Font-lock keywords for `slog-mode'.")

;;;; ------------------------------------------------------------------ ;;;;
;;;; Indentation
;;;; ------------------------------------------------------------------ ;;;;

(defun slog--line-starts-toplevel-p ()
  "Return non-nil if the current line's first token is a top-level keyword."
  (save-excursion
    (back-to-indentation)
    (and (looking-at "\\_<\\([a-z]+\\)\\_>")
         (member (match-string-no-properties 1) slog-top-level-keywords)
         t)))

(defun slog--line-starts-arrow-p ()
  "Return non-nil if the current line's first token is a rule arrow."
  (save-excursion
    (back-to-indentation)
    (looking-at "\\(?:<--\\|-->\\|<-\\)\\(?:[ \t]\\|$\\)")))

(defun slog--line-is-comment-p ()
  "Return non-nil if the current line's first token is a `;;' comment."
  (save-excursion
    (back-to-indentation)
    (looking-at ";;")))

(defun slog--first-clause-column ()
  "Return the column of the first clause on the line point is on.
Point is assumed to be at `back-to-indentation'.  A leading rule arrow or
top-level keyword is skipped when a clause follows it on the same line, so
that continuation clauses line up under the first clause of the form (the
style used in both the `HEAD <-- BODY' and `BODY --> HEAD' rule shapes).
When the arrow/keyword stands alone on its line, its own column is kept."
  (let ((start (point)))
    (when (or (looking-at "\\(?:<--\\|-->\\|<-\\)")
              (and (looking-at "\\_<\\([a-z]+\\)\\_>")
                   (member (match-string-no-properties 1)
                           slog-top-level-keywords)))
      (goto-char (match-end 0))
      (skip-chars-forward " \t")
      (when (or (eolp) (looking-at ";;"))
        (goto-char start)))            ; nothing followed: keep own column
    (current-column)))

(defun slog--form-clause-column ()
  "Return the column at which clauses of the enclosing top-level form align.
This is the column of the first clause on the form's keyword line, e.g. 5 for
a `rule (head ...)' line -- so every body and head clause of the rule lines up
there.  When the keyword stands alone on its line (the usual `facts' layout)
the keyword's own column (normally 0) is used instead."
  (save-excursion
    (beginning-of-line)
    (let ((found nil))
      (while (and (not found) (not (bobp)))
        (forward-line -1)
        (when (and (zerop (car (syntax-ppss (line-beginning-position))))
                   (progn (back-to-indentation)
                          (and (looking-at "\\_<\\([a-z]+\\)\\_>")
                               (member (match-string-no-properties 1)
                                       slog-top-level-keywords))))
          (setq found t)))
      (if found
          (progn (back-to-indentation) (slog--first-clause-column))
        0))))

(defun slog--inside-paren-indent (open)
  "Compute indentation for a line inside the bracketed form opening at OPEN."
  (save-excursion
    (goto-char open)
    (let ((open-col (current-column)))
      (forward-char 1)
      (skip-chars-forward " \t")
      (cond
       ;; Nothing after the open bracket: indent one level in.
       ((or (eolp) (looking-at ";;"))
        (+ open-col slog-indent-offset))
       (t
        (let ((head-col (current-column)))
          (condition-case nil
              (progn
                (forward-sexp 1)          ; step over the head element
                (skip-chars-forward " \t")
                (if (or (eolp) (looking-at ";;"))
                    ;; Head sits alone on the opening line: line arguments
                    ;; up under the head.
                    head-col
                  ;; There is a first argument on the opening line: line the
                  ;; continuation up under it.
                  (current-column)))
            (error head-col))))))))

(defun slog--calculate-indent ()
  "Return the desired indentation column for the current line, or nil."
  (save-excursion
    (beginning-of-line)
    (let* ((ppss (syntax-ppss))
           (depth (nth 0 ppss))
           (in-string (nth 3 ppss))
           (open (nth 1 ppss)))
      (cond
       (in-string nil)                       ; leave string interiors alone
       ;; A whole-line comment at top level is a section divider / doc line:
       ;; keep it flush left rather than dragging it under a clause above.
       ((and (= depth 0) (slog--line-is-comment-p)) 0)
       ((> depth 0) (slog--inside-paren-indent open))
       ((slog--line-starts-toplevel-p) 0)
       ((slog--line-starts-arrow-p) slog-arrow-offset)
       (t (slog--form-clause-column))))))

(defun slog-indent-line ()
  "Indent the current line as Slog code."
  (interactive)
  (let ((indent (slog--calculate-indent)))
    (if (null indent)
        'noindent
      (let ((pos (- (point-max) (point))))
        (indent-line-to indent)
        ;; Restore point if it was to the right of the indentation.
        (when (> (- (point-max) pos) (point))
          (goto-char (- (point-max) pos)))))))

;;;; ------------------------------------------------------------------ ;;;;
;;;; imenu + navigation
;;;; ------------------------------------------------------------------ ;;;;

(defvar slog-imenu-generic-expression
  (let ((name "(\\s-*\\([^ \t\n()]+\\)"))
    `(("Struct"  ,(concat "^\\s-*struct[ \t]*"  name) 1)
      ("Union"   ,(concat "^\\s-*union[ \t]*"   name) 1)
      ("Enum"    ,(concat "^\\s-*enum[ \t]*"    name) 1)
      ("Table"   ,(concat "^\\s-*table[ \t]*"   name) 1)
      ("Lattice" ,(concat "^\\s-*lattice[ \t]*" name) 1)
      ("Demand"  ,(concat "^\\s-*demand[ \t]*"  name) 1)
      ("Extern"  ,(concat "^\\s-*extern[ \t]+[^ \t\n()]+[ \t]*" name) 1)))
  "`imenu-generic-expression' for `slog-mode'.")

(defun slog-beginning-of-defun (&optional arg)
  "Move backward to the start of a top-level Slog form.
Move ARG forms (default 1); negative ARG moves forward."
  (interactive "^p")
  (setq arg (or arg 1))
  (let ((step (if (< arg 0) 1 -1))
        (count (abs arg)))
    (while (> count 0)
      (forward-line step)
      (while (and (not (bobp)) (not (eobp))
                  (not (and (zerop (car (syntax-ppss (line-beginning-position))))
                            (slog--line-starts-toplevel-p))))
        (forward-line step))
      (setq count (1- count)))
    (back-to-indentation)))

;;;; ------------------------------------------------------------------ ;;;;
;;;; Mode definition
;;;; ------------------------------------------------------------------ ;;;;

(defvar slog-mode-map
  (let ((map (make-sparse-keymap)))
    map)
  "Keymap for `slog-mode'.")

;;;###autoload
(define-derived-mode slog-mode prog-mode "Slog"
  "Major mode for editing Slog source files.

\\{slog-mode-map}"
  :syntax-table slog-mode-syntax-table
  ;; Comments.
  (setq-local comment-start ";; ")
  (setq-local comment-end "")
  (setq-local comment-start-skip ";;+[ \t]*")
  (setq-local comment-use-syntax t)
  ;; Font lock.
  (setq-local font-lock-defaults '(slog-font-lock-keywords))
  ;; Indentation: spaces only, never a literal tab.
  (setq-local indent-tabs-mode nil)
  (setq-local indent-line-function #'slog-indent-line)
  (setq-local electric-indent-inhibit nil)
  ;; Navigation / tooling.
  (setq-local beginning-of-defun-function #'slog-beginning-of-defun)
  (setq-local imenu-generic-expression slog-imenu-generic-expression)
  (setq-local imenu-case-fold-search nil))

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.slog\\'" . slog-mode))

(provide 'slog-mode)

;;; slog-mode.el ends here
