#!/usr/bin/python
import sys

def pArg():
	toPrint = "No Arguments !"
	sys.argv.pop(0)
	if len((sys.argv)) > 0 :
		toPrint = ' '.join(sys.argv)
	print toPrint
	return
