#!/bin/python

import sys

name = sys.argv[1]

with open(name + "/list.txt", "r", encoding="utf-8") as file:
	executables = [name + "/" + x for x in file.read().split()]
	

