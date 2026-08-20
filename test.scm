(load "tsmat.scm")

(define device10
	'(	10
		(READ 20 200)
		(SEND 20 200)
		(ADD 20 100)
		(IF 20 ABC)
		(EMPTY ABC 0)
		(PUSH 20 0)
		(POP 20 0)
		(LABEL ABC 0)
		(HALT 0 0)))
#|
(display
	(apply string-append 
		(map instruction->string
			'((READ 20 200)
				(SEND 20 200)
				(ADD 20 100)
				(IF 20 ABC)
				(EMPTY ABC 0)
				(PUSH 20 0)
				(POP 20 0)
				(LABEL ABC 0)
				(HALT 0 0)))))
|#
(display (description->c++ device10))