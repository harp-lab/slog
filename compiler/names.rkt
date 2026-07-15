#lang racket

;; The qualified-name (QName) authority (docs/modules.md §8.1, N0;
;; docs/n0-seam-map.md).  A QName is a nonempty path of components; its
;; LOWERED form -- the representation the whole symbol-keyed middle end,
;; the daemon, and persistence carry -- is the dotted symbol whose printed
;; form joins the components with ".".  Because a component can never
;; contain a dot (valid-component? below matches the lexer's identifier
;; alphabet), the lowering is collision-free and reversible: a.bc.r and
;; ab.c.r are distinct symbols, and splitting on "." recovers exactly the
;; original components.
;;
;; The load-bearing N0 invariant (byte-identity gate): for every
;; single-component name x, (qname->symbol (qname (list "x"))) is
;; literally 'x -- root-level programs, cache keys, plan keys, daemon
;; signatures, and goldens are byte-for-byte unchanged until dotted names
;; actually appear in source.
;;
;; No other pass may join or split name components.  Prefix substitution
;; (N2's namespace binding) belongs here when it arrives.

(provide valid-component?
         qname            ; (listof string) -> qname (validated)
         qname?
         qname-components ; qname -> (listof string)
         qname-root?      ; single-component?
         qname=?
         qname<?
         qname->symbol    ; the lowering (dotted symbol)
         symbol->qname    ; the inverse (splits on ".")
         qname-symbol?    ; symbol contains a dot (i.e. multi-component)?
         qname-join       ; symbol symbol -> symbol   (the parser's helper)
         qname->display   ; human-facing dotted string
         qname->wire      ; action strings / schema replies (validated)
         wire->qname
         qname->fs-name   ; data/ directory + CSV name component (validated)
         fs-name->qname
         qname->cxx-ident ; C++ identifier form (the _0XXXX scheme)
         qname-derive)    ; owner + role -> generated companion name

(require "utils.rkt")

;; A component follows the lexer's identifier rule (compiler/lexer.rkt):
;; one or more of [A-Za-z0-9_'], never a dot.  (The lexer additionally
;; requires the first char not be a prime; we accept the lexer's output,
;; so the shape check is sufficient and deliberately not stricter.)
(define component-rx #rx"^[A-Za-z0-9_][A-Za-z0-9_']*$")

(define (valid-component? s)
  (and (string? s) (regexp-match? component-rx s)))

;; Representation: the canonical carrier is the lowered symbol itself; the
;; structured view is derived on demand.  This keeps N0 zero-cost for the
;; middle end (symbols in, symbols out) while making this module the only
;; place that knows the encoding.
(struct qname-rep (components) #:transparent)

(define (qname comps)
  (unless (and (list? comps) (pair? comps) (andmap valid-component? comps))
    (error 'qname "invalid name components: ~a" comps))
  (qname-rep comps))

(define (qname? x) (qname-rep? x))
(define (qname-components q) (qname-rep-components q))
(define (qname-root? q) (null? (cdr (qname-rep-components q))))

(define (qname=? a b) (equal? (qname-rep-components a) (qname-rep-components b)))

;; Total order = string order of the lowered form, so sorts that feed
;; cache keys (compile.rkt progstr, canonical-plan.rkt) see exactly the
;; symbol<? order they already use.
(define (qname<? a b)
  (string<? (qname->display a) (qname->display b)))

(define (qname->display q)
  (string-join (qname-rep-components q) "."))

(define (qname->symbol q)
  (string->symbol (qname->display q)))

(define (symbol->qname s)
  (define parts (string-split (symbol->string s) "." #:trim? #f))
  (unless (andmap valid-component? parts)
    (error 'symbol->qname "not a valid lowered qname: ~a" s))
  (qname parts))

;; Is this lowered symbol multi-component?  (Cheap test used by passes
;; that must NOT treat dotted names as plain locals, e.g. future N1
;; qualification; root symbols answer #f.)
(define (qname-symbol? s)
  (and (symbol? s) (string-contains? (symbol->string s) ".")))

;; The parser's collapse helper: join two lowered names (each a bare id
;; or an already-collapsed dotted symbol) into one.  Validation rides on
;; symbol->qname of the result at the few places that decode; the parser
;; only ever joins lexer id tokens, which are valid by construction.
(define (qname-join a b)
  (string->symbol (string-append (symbol->string a) "." (symbol->string b))))

;; Wire and filesystem codecs.  Both layers already tolerate dots (the
;; daemon and runslog split relation directories on the LAST ".arity.",
;; and schema replies delimit names by spaces) -- so the codec is the
;; validated identity.  Centralizing it here means a future component
;; alphabet change (or an escaping need) edits one place.
(define (qname->wire q) (qname->display q))
(define (wire->qname s) (symbol->qname (string->symbol s)))
(define (qname->fs-name q) (qname->display q))
(define (fs-name->qname s) (symbol->qname (string->symbol s)))

;; C++ identifier mangling: relation names reach generated code as string
;; literals (never identifiers), so this is for the rare identifier-shaped
;; need; it MUST stay the escape-id-for-C scheme, whose _0XXXX hex
;; encoding is pinned by tests (a dot maps to _0002e).
(define (qname->cxx-ident q)
  (escape-id-for-C (qname->symbol q)))

;; Owner-scoped generated names (docs/modules.md §8.3): companions belong
;; to their owner structurally.  Operating on the LOWERED symbol keeps
;; today's spellings byte-identical for root owners (reach + has ->
;; reach_has) while multi-component owners compose safely
;; (m.reach + has -> m.reach_has -- the suffix extends the last
;; component, so the companion lives beside its owner in the same
;; namespace).
(define (qname-derive owner role)
  (string->symbol
   (string-append (symbol->string owner)
                  "_"
                  (symbol->string role))))
