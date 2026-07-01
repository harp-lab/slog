#lang racket

(provide rule?
         primitive-cmp?
         cmp-prim-name)

(define (primitive-unarop? x)
  (match x
    [(or 'size 'neg 'abs 'bnot
         'sqrt 'sin 'cos 'tan 'exp 'log 'floor 'ceil 'round
         'tofloat 'toint) #t]
    [_ #f]))

(define (primitive-binop? x)
  (match x
    [(or '- '+ '* '/ '% 'min 'max 'pow
         'band 'bor 'bxor 'shl 'shr) #t]
    [_ #f]))

(define (primitive-triarop? x)
  (match x
    ['substr #t]
    [_ #f]))

;; Ordering comparisons are body guards (filters), not value-producing prims:
;; `(< x y)` behaves like `/=`, keeping only tuples where the relation holds.
(define (primitive-cmp? x)
  (match x
    [(or '< '<= '> '>=) #t]
    [_ #f]))

;; The runtime prim function base name (daemon/prims.h) for a comparison op.
;; Chosen alnum so escape-id-for-C leaves it untouched.
(define (cmp-prim-name op)
  (match op
    ['<  'lt]
    ['<= 'le]
    ['>  'gt]
    ['>= 'ge]))

(define (slog-const? x)
  (match x
    [(? number?) #t]
    [(? string?) #t]
    [_ #f]))

(define (sub-cls-arg? x)
  (match x
    [(? symbol?) #t]
    [`(const ,(? slog-const?)) #t]
    [_ #f]))

(define (sub-cls? x)
  (match x
    [(? sub-cls-arg?) #t]
    [`(,(? primitive-unarop?) ,fst) (sub-cls-arg? fst)]
    [`(,(? primitive-binop?) ,fst ,snd) (and (sub-cls-arg? fst) (sub-cls-arg? snd))]
    [`(,(? primitive-triarop?) ,fst ,snd ,thrd)
     (and (sub-cls-arg? fst) (sub-cls-arg? snd) (sub-cls-arg? thrd))]
    [`(,name ,args ...) (and (symbol? name) (andmap sub-cls-arg? args))]
    [_ #f]))

(define (hd-cls? x)
  (match x
    [`(= ,fst ,snd) (and (sub-cls? fst) (sub-cls? snd))]
    [`(,name ,args ...) (and (symbol? name) (andmap sub-cls? args))]
    [_ #f]))

(define (bdy-cls? x)
  (match x
    [`(= ,fst ,snd) (and (sub-cls? fst) (sub-cls? snd))]
    [`(/= ,fst ,snd) (and (sub-cls? fst) (sub-cls? snd))]
    [`(,name ,args ...) (and (symbol? name) (andmap sub-cls? args))]
    [_ #f]))

(define (rule? x)
  (match x
    [`(rule ,bdy ... --> ,hd ...)
     (and (list? hd) (andmap hd-cls? hd) (list? bdy) (andmap bdy-cls? bdy))]
    [_ #f]))
