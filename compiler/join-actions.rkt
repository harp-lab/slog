#lang racket

;; Physical join-planning vocabulary shared by join-planning and
;; operationalization.  A logical relation occurrence receives one stable,
;; rule-local identity before semi-naive versions are scheduled.  Each version
;; then attaches its logical read view to an access.  Scalar actions consume
;; one access; Expand3 consumes two accesses atomically and binds their shared
;; key-simple cycle variable.

(provide (struct-out join-occurrence)
         (struct-out join-access)
         (struct-out scalar-join-action)
         (struct-out expand3-action)
         join-view?
         access-clause access-id access-rel access-tuple access-vars
         action-accesses action-vars action-out-vars action-occurrence-ids)

(require "ir-shared.rkt")

;; dynamic-index is #f for a non-dynamic/static occurrence and otherwise its
;; ordinal in the staged rule's original dynamic-occurrence order.
(struct join-occurrence
  (id clause source-index dynamic-index static?)
  #:transparent)

;; view is one of DELTA/FULL/OLD/NEW, assigned before physical scheduling.
(struct join-access (occurrence view) #:transparent)

(struct scalar-join-action (access) #:transparent)
(struct expand3-action (cycle left right) #:transparent)

(define (join-view? v) (memq v '(delta full old new)))

(define (access-clause a)
  (join-occurrence-clause (join-access-occurrence a)))

(define (access-id a)
  (join-occurrence-id (join-access-occurrence a)))

(define (access-rel a)
  (match (access-clause a)
    [`(syn ,_ = ,_ (syn ,_ ,name ,_ ...)) name]
    [`(syn ,_ ,name ,_ ...) name]))

(define (access-tuple a)
  (match (access-clause a)
    [`(syn ,_ = ,x (syn ,_ ,_ ,xs ...)) (cons x xs)]
    [`(syn ,_ ,_ ,xs ...) xs]))

(define (access-vars a) (clause-vars (access-clause a)))

(define (action-accesses a)
  (cond
    [(scalar-join-action? a) (list (scalar-join-action-access a))]
    [(expand3-action? a) (list (expand3-action-left a)
                               (expand3-action-right a))]
    [else (error 'action-accesses "not a join action: ~a" a)]))

(define (action-vars a)
  (for/fold ([vs (set)]) ([access (in-list (action-accesses a))])
    (set-union vs (access-vars access))))

(define (action-out-vars a ground)
  (set-subtract (action-vars a) ground))

(define (action-occurrence-ids a)
  (map access-id (action-accesses a)))
