#!/bin/chicken-csi -s

#| Written by hand, only use of AI was for 
figuring out how to use commandline arguments and file IO |#

(import (chicken file))
(import (chicken process))
(import (chicken process-context))

(define (instruction->string instruction)
	(let
		((command (car instruction))
			(arg1 (if (> (length instruction) 1) (cadr instruction) #f))
			(arg2 (if (> (length instruction) 2) (caddr instruction) #f)))
		(cond
			((eq? command 'READ)
				(string-append
					"cout << \"0\\n\"<< flush;\n"
					"cin >> a["
					(number->string arg1)
					"];\n"))
			((eq? command 'SEND)
				(string-append
					"cout << \"1 \" << a["
					(number->string arg1)
					"] << ' ' << "
					(number->string arg2)
					" << '\\n' << flush;\n"))
			((eq? command 'READIN)
				(string-append
					"cout << \"2\\n\"<< flush;\n"
					"cin >> a["
					(number->string arg1)
					"];\n"))
			((eq? command 'SENDOUT)
				(string-append
					"cout << \"3 \" << a["
					(number->string arg1)
					"] << '\\n' << flush;\n"))
			((eq? command 'ADD)
				(string-append
					"a["
					(number->string arg1)
					"]+="
					(number->string arg2)
					";\n"
					"a["
					(number->string arg1)
					"]%=256;\n"))
			((eq? command 'IF)
				(string-append
					"if(a["
					(number->string arg1)
					"])goto "
					(symbol->string arg2)
					";\n"))
					
			((eq? command 'EMPTY)
				(string-append
					"if(s.empty())goto "
					(symbol->string arg1)
					";\n"))
			((eq? command 'PUSH)
				(string-append
					"s.push(a["
					(number->string arg1)
					"]);\n"))
			((eq? command 'POP)
				(string-append
					"a["
					(number->string arg1)
					"]=s.top();\n"
					"s.pop();\n"))
			
			((eq? command 'LABEL)
				(string-append
					(symbol->string arg1)
					":\n"))
			((eq? command 'HALT)
				(string-append
					"cout << \"4\\n\";\n"
					"return 0;\n"))
			(#t ""))))
			
(define pre-boilerplate
	(string-append
		"#include <iostream>\n"
		"#include <stack>\n"
		"using namespace std;\n"
		"int main(){\n"
		"int a[256] = {};\n"
		"stack<int> s;\n"))
		
(define post-boilerplate "}\n")

(define (description->c++ description)
	(string-append
		pre-boilerplate
		(apply string-append
			(map instruction->string (cdr description)))
		post-boilerplate))

(define (create-program full-description name)
	(if (directory-exists? name) (delete-directory name #t) #f)
	(create-directory name)
	(map
		(lambda (description)
			(call-with-output-file
				(string-append
					name
					"/"
					(number->string (car description))
					".cpp")
				(lambda (out)
					(display (description->c++ description) out))))
		full-description)
	(call-with-output-file
		(string-append
			name
			"/list.txt")
		(lambda (out)
			(display
				(apply string-append
					(cons
						"" ;;; (number->string (length full-description))
						(cons "" ;;; "\n"
							(map
								(lambda (x) (string-append (number->string x) " "))
								(map car full-description)))))
				out))))
				
(define (call-g++ full-description name)
	(map
		(lambda (device)
			(system
				(string-append "g++ "
					name
					"/"
					(number->string device)
					".cpp -o "
					name
					"/"
					(number->string device))))
		(map car full-description)))

(define (compile full-description name)
	(create-program full-description name)
	(call-g++ full-description name))
	
(let* 
	(	(infile (car (command-line-arguments)))
		(name
			(if (= (length (command-line-arguments)) 2)
				(cadr (command-line-arguments))
				(string-append infile ".compiled"))))
	(compile
		(call-with-input-file infile
			(lambda (in) (read in)))
		name))
