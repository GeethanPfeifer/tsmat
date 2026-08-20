A stack machine is only as powerful as a pushdown automaton.
However, if you have two (or more) stack machines that can interact with each other, they are as powerful as a Turing machine.

This program, tentatively titled "tsmat" illustrates this concept.
"tsmat.scm" takes a list of descriptions of stack machines, converts them to C++ code, and gcc compiles them.
Then, "controller.py" controls their interaction.

As an example description (not a very enlightening one, but it gives all the possible commands), see example0.tsmat.
To run it, run the following commands:
$ ./tsmat.scm example0.tsmat
$ ./controller.py example0.tsmat.compiled

For a more interesting example, try the brainfuck interpreter written by ChatGPT.
You'll have to use Ctrl-D to delimit between the program and input.
As far as I can tell, it works.



License:
Everything in this directory (including this README) and all subdirectories contained within is licensed under the Unlicense. See LICENSE for a copy of said license.
The gist of the license is that I'm placing this code in the public domain: that means that you do not (legally, you still may be required to in order to avoid plagiarism for academic work) have to attribute any code in this directory (though I would appreciate it if you did), and you may use it for any purpose.


AI disclosure:
AI was used to create the controller (python is a pain), and to generate the brainfuck program (as fun as it would be, I simply don't have the time).
AI was also used for figuring out basic commands wrt. file I/O and getting commandline arguments.

The compiler was written by hand (scheme is a joy), and the idea is also my own, for the most part (it's not a new idea).
