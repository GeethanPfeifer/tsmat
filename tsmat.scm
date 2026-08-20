(define (instruction->string instruction)
	(let
		((command (car instruction))
			(arg1 (cadr instruction))
			(arg2 (caddr instruction)))
		(cond
			((eq? command 'READ)
				(string-append
					"cout << \"0 \" << "
					(number->string arg2)
					" << '\\n';\n"
					"cin >> a["
					(number->string arg1)
					"];\n"))
			((eq? command 'SEND)
				(string-append
					"cout << \"1 \" << a["
					(number->string arg1)
					"] << ' ' << "
					(number->string arg2)
					" << '\\n';\n"))
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
					"cout << \"2\\n\";\n"
					"return 0;\n"))
			(#t ""))))