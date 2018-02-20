#!/usr/bin/python
import sys

#
# ComputerV1
#
# ./computerv1.py <expression>
#
# Examples:
#  5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0
#  4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
#  5 * X^0 + 4 * X^1 = 4 * X^0
#  1 * X^0 + 4 * X^1 = 0
#  8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0
#  5 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 0
#  5 + 4 * X + X^2= X^2
#

def printl(bool):
	print ("\033[31m--------------------------------------------------\033[39m")
	if bool == 1:
		exit()

class Computor():
	equation = 0
	degree = 0
	arg = 0

	def __init__(self, equation = 0, degree = 0, arg = 0):
		self.equation = equation
		self.degree = degree
		self.arg = arg
		sys.argv.pop(0)
		if len((sys.argv)) == 1:
			self.equation = "Equation: " + sys.argv[0]
			self.arg = 1
		else:
			self.equation = "Not enough argument"
			self.arg = -1

computor = Computor();
printl(0)
print(computor.equation)
if computor.arg == -1:
	printl(1)
printl(1)