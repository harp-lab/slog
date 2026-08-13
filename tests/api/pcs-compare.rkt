#lang racket

;; The joint battery's drift gate: compare a PRODUCER-EMITTED fixture
;; against its golden-corpus counterpart at the semantic-section level
;; (docs/activation-contract.md §6: "so the fixture cannot drift into a
;; parallel informal ABI").  Byte equality is not the claim -- the corpus
;; files are hand-authored with illustrative image keys and instance-scoped
;; writer lists -- the claim is that the two sides agree on every field the
;; consumer RESOLVES with:
;;
;;   rebuild set  == corpus rebuild set     (the cone's slots, exactly)
;;   retire  set  == corpus retire set
;;   carry   set  ⊇ corpus carry set        (the producer also carries the
;;                                           implicit diagnostic relations)
;;   roots / cone == corpus roots / cone
;;   writers      ⊇ corpus writers          (corpus scopes to the replaced
;;                                           instance; the producer is total)
;;   occurrences  ⊇ corpus replaced set     (a textual main change makes the
;;                                           root an explicit replacement too)
;;   rule new-slots ⊇ corpus new-slots
;;   sccs (new)   ⊆ corpus sccs, covering every cone member the corpus sccs
;;                  cover (the producer restricts to the cone; some corpus
;;                  fixtures also list outside-cone strata illustratively)
;;
;;   racket tests/api/pcs-compare.rkt EMITTED.pcs CORPUS.pcs

(require racket/string
         racket/set
         "../../compiler/activation.rkt")

(match-define (list emitted-path corpus-path)
  (vector->list (current-command-line-arguments)))

(define (load-fixture path)
  (define raw (file->string path))
  (define vslots (make-hash))
  (define substituted
    (regexp-replace*
     #px"@V:([A-Za-z0-9_.]+)@"
     (string-replace (string-replace raw "@BASE-PROGRAM@" "p1:layer-base:0")
                     "@BASE-BOUNDARY@" "b1:layer-base:0")
     (lambda (_ rel)
       (format "v1:layer-base:0:~a"
               (hash-ref! vslots rel (lambda () (hash-count vslots)))))))
  (define cs (parse-change-set (read (open-input-string substituted))))
  (when (activation-refusal? cs)
    (error 'pcs-compare "~a did not parse: ~a" path cs))
  cs)

(define emitted (load-fixture emitted-path))
(define corpus (load-fixture corpus-path))

(define failures '())
(define (check! name ok? detail)
  (unless ok? (set! failures (cons (list name detail) failures))))

(define (dispositions cs disp)
  (for/set ([row (in-list (change-set-slot-lineage cs))]
            #:when (eq? (third row) disp))
    (first row)))

(define (as-set xs) (list->set xs))

(check! 'rebuild-set
        (equal? (dispositions emitted 'rebuild) (dispositions corpus 'rebuild))
        (list (dispositions emitted 'rebuild) (dispositions corpus 'rebuild)))
(check! 'retire-set
        (equal? (dispositions emitted 'retire) (dispositions corpus 'retire))
        (list (dispositions emitted 'retire) (dispositions corpus 'retire)))
(check! 'carry-superset
        (subset? (dispositions corpus 'carry) (dispositions emitted 'carry))
        (list (dispositions emitted 'carry) (dispositions corpus 'carry)))
(check! 'roots
        (equal? (as-set (change-set-affected-roots emitted))
                (as-set (change-set-affected-roots corpus)))
        (list (change-set-affected-roots emitted)
              (change-set-affected-roots corpus)))
(check! 'cone
        (equal? (as-set (change-set-affected-cone emitted))
                (as-set (change-set-affected-cone corpus)))
        (list (change-set-affected-cone emitted)
              (change-set-affected-cone corpus)))
(check! 'writers-old
        (subset? (as-set (change-set-writers-old corpus))
                 (as-set (change-set-writers-old emitted)))
        (list (change-set-writers-old emitted)
              (change-set-writers-old corpus)))
(check! 'writers-new
        (subset? (as-set (change-set-writers-new corpus))
                 (as-set (change-set-writers-new emitted)))
        (list (change-set-writers-new emitted)
              (change-set-writers-new corpus)))
(check! 'occurrences
        (subset? (as-set (map first (change-set-occurrences corpus)))
                 (as-set (map first (change-set-occurrences emitted))))
        (list (map first (change-set-occurrences emitted))
              (map first (change-set-occurrences corpus))))
(check! 'rule-new-slots
        (subset? (as-set (map second (change-set-rule-lineage corpus)))
                 (as-set (map second (change-set-rule-lineage emitted))))
        (list (map second (change-set-rule-lineage emitted))
              (map second (change-set-rule-lineage corpus))))

;; sccs: emitted rows (level, member-set) must appear in the corpus rows,
;; and together the emitted rows must cover every cone member the corpus
;; rows cover.
(define (scc-shapes cs)
  (for/set ([row (in-list (change-set-sccs-new cs))])
    (list (second row) (as-set (third row)))))
(define (scc-members cs)
  (for/fold ([members (set)]) ([row (in-list (change-set-sccs-new cs))])
    (set-union members (as-set (third row)))))
(check! 'sccs-subset
        (subset? (scc-shapes emitted) (scc-shapes corpus))
        (list (scc-shapes emitted) (scc-shapes corpus)))
(check! 'sccs-cover-cone
        (subset? (set-intersect (scc-members corpus)
                                (as-set (change-set-affected-cone corpus)))
                 (scc-members emitted))
        (list (scc-members emitted) (scc-members corpus)))

(cond
  [(null? failures)
   (printf "(compare-ok ~a ~a)\n" emitted-path corpus-path)
   (exit 0)]
  [else
   (for ([f (in-list (reverse failures))])
     (printf "(compare-failed ~a ~s)\n" (first f) (second f)))
   (exit 1)])
