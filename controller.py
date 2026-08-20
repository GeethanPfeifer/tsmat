#!/bin/python

import sys
import subprocess
import select

name = sys.argv[1]

with open("./" + name + "/list.txt", "r", encoding="utf-8") as file:
	executables = file.read().split()

workers = {}
for ex in executables:
	workers[ex] = subprocess.Popen(
		["./" + name + "/" + ex],
		stdin=subprocess.PIPE,
		stdout=subprocess.PIPE,
		stderr=subprocess.PIPE,
		text=True,
		bufsize=1,
	)

halted = False
while not halted:
	# reading from the workers
	for ex in executables:
		ready, _, _ = select.select([workers[ex].stdout], [], [], 0)
		if ready:
			com = [int(x) for x in workers[ex].stdout.readline().split()]
			# HALT SIGNAL
			if com[0]==4:
				halted = True
				break
			# NOTE: command 0 basically does nothing
			if com[0]==1:
				recipient = workers[str(com[2])]
				if recipient.poll() is None:
					recipient.stdin.write(str(com[1]) + "\n")
					recipient.stdin.flush()
				else:
					halted = True
					break
			if com[0]==2:
				workers[ex].stdin.write(str(sys.stdin.buffer.read(1)[0]))
				workers[ex].stdin.flush()
			if com[0] == 3:
				sys.stdout.buffer.write(bytes([com[1]]))
				sys.stdout.buffer.flush()
				
				
	
