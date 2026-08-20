#!/usr/bin/env python3

# Basically written entirely by ChatGPT
# https://chatgpt.com/share/6a86daf9-83d4-83ec-acaf-1aadba19ccfe

import sys
import subprocess
import select
from collections import deque

name = sys.argv[1]

with open(f"./{name}/list.txt") as f:
    executables = f.read().split()

workers = {
    ex: subprocess.Popen(
        [f"./{name}/{ex}"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        bufsize=0,
    )
    for ex in executables
}

by_stdout = {p.stdout: ex for ex, p in workers.items()}
mail = {ex: deque() for ex in executables}
waiting = set()


def reply(ex, x):
    workers[ex].stdin.write(f"{x}\n".encode())
    workers[ex].stdin.flush()


halted = False

while not halted:
    alive = [p.stdout for p in workers.values() if p.poll() is None]
    if not alive:
        break

    ready, _, _ = select.select(alive, [], [])

    for out in ready:
        ex = by_stdout[out]
        line = out.readline()

        if not line:
            continue

        com = list(map(int, line.split()))
        op = com[0]

        if op == 0:                         # READ
            if mail[ex]:
                reply(ex, mail[ex].popleft())
            else:
                waiting.add(ex)

        elif op == 1:                       # SEND value recipient
            value, recipient = com[1], str(com[2])

            if recipient in waiting:
                waiting.remove(recipient)
                reply(recipient, value)
            else:
                mail[recipient].append(value)

        elif op == 2:                       # READIN
            b = sys.stdin.buffer.read(1)
            reply(ex, b[0] if b else 0)

        elif op == 3:                       # SENDOUT value
            sys.stdout.buffer.write(bytes([com[1]]))
            sys.stdout.buffer.flush()

        elif op == 4:                       # HALT
            halted = True
            break


for p in workers.values():
    if p.poll() is None:
        p.terminate()