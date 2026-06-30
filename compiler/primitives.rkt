#lang racket

(provide prim-fun-env)

(define prim-fun-env
  (apply hash
         `(size (fun any -> int)
                substr
                (fun str int int -> str)
                -
                (fun A A -> A)
                +
                (fun A A -> A)
                *
                (fun A A -> A)
                /
                (fun A A -> A)
                %
                (fun A A -> A))))
