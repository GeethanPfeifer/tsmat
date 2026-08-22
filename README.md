# tsmat

A stack machine is only as powerful as a pushdown automaton. But, two or more stack machines interacting with each other are as powerful as a Turing Machine. That is the idea behind tsmat.

## Name

"tsmat" is an acronym for "two stack [machines] make a Turing [machine]".

## Syntax

A tsmat program is a S-expression that is a list of stack machine descriptions.

 `(<stack machine A> <stack machine B> ... <last stack machine>)`

Each stack machine description is a list with the first element being a number identifying that stack machine, and all subsequent elements being statements.

 `(<id> <statement 1> <statement 2> ... <statement n>)`

A statement is a list with the first element being a symbol (indicating the type of statement), and all subsequent elements being arguments.

The following is a list of all types of statements:

```
 (READ <INT: n>)             ;;; Wait to be sent a byte from another stack machine, store in register n.
 (SEND <INT: n> <INT: m>)    ;;; Send the contents of register n to stack machine m.
 (READIN <INT: n>)           ;;; Read a byte from stdin, store in register n.
 (SENDOUT <INT: n>)          ;;; Send the contents of register n to stdout.
 
 (ADD <INT: n> <INT: m>)     ;;; Adds the integer m to the contents of register n.
 
 (PUSH <INT: n>)             ;;; Pushes the contents of register n to the stack.
 (POP <INT: n>)              ;;; Pops the stack, storing in register n.
 
 (LABEL <SYM: s>)            ;;; A label. The symbol should be a only alphabetic characters.
 (IF <INT: n> <SYM: s>)      ;;; If the contents of register n are positive, goto label s. Otherwise, continue.
 (EMPTY <SYM: s>)            ;;; If the stack is empty, goto label s. Otherwise, continue.
 
 (HALT)                      ;;; Sends a signal to all stack machines to stop, and stops itself.
```

We inherit specific S-expression syntax, including comments, from lisp (for my implementation, specifically chicken scheme.)

## Semantics

Commands are run sequentially, except for instructions that go to specific labels.

All stack machines are run concurrently. In the case of race conditions, behavior is intentionally unspecified; it is expected that programmers deal with this themselves.

There are 256 registers (numbered 0-255), each holding an unsigned byte. Addition overflows, e.g. 128 + 129 = 1.

Stacks of unbounded length, and store unsigned bytes.

## Implementation details

"tsmat.scm" takes a list of descriptions of stack machines, converts them to C++ code, and gcc compiles them.

Then, "controller.py" controls their interaction.

Chicken scheme is required to run the compiler, and it's assumed that its binary location is `/bin/chicken-csi`. This is the binary location on Arch Linux, but I believe it is different on other distributions.

To run a program, first compile it, and then run the controller.

```
./tsmat.scm example0.tsmat
./controller.py example0.tsmat.compiled
```

## Brainfuck Implementation

ChatGPT wrote a brainfuck interpreter in this language, see `chatgpt_bf.tsmat`.

You'll have to use Ctrl-D to delimit between the program and input.

As far as I can tell, it works.

## License

Everything in this directory (including this README) and all subdirectories contained within is licensed under the Unlicense. See LICENSE for a copy of said license.

The gist of the license is that I'm placing this code in the public domain: that means that you do not (legally, you still may be required to in order to avoid plagiarism for academic work) have to attribute any code in this directory (though I would appreciate it if you did), and you may use it for any purpose.

## Link on esolangs

https://esolangs.org/wiki/Tsmat

## AI disclosure

AI was used to create the controller (python is a pain), and to generate the brainfuck program (as fun as it would be, I simply don't have the time).

AI was also used for figuring out basic commands wrt. file I/O and getting commandline arguments, and some debugging.

See https://chatgpt.com/share/6a86daf9-83d4-83ec-acaf-1aadba19ccfe

The compiler was written by hand (scheme is a joy), and the idea is also my own, for the most part (it's not a new idea).
