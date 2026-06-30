#lang racket

(provide rule?)

(define (primitive-unarop? x)
  (match x
    ['size #t]
    [_ #f]))

(define (primitive-binop? x)
  (match x
    ['- #t]
    ['+ #t]
    ['* #t]
    ['/ #t]
    ['% #t]
    [_ #f]))

(define (primitive-triarop? x)
  (match x
    ['substr #t]
    [_ #f]))

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
