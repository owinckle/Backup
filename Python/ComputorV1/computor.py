#!/usr/bin/python
import sys
from time import sleep

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

def header(bool):
	if bool == 0:
		print("\033[36m")
		print(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -") ; sleep(0.07)
		print("|    ******                                         **                               **   |") ; sleep(0.07)
		print("|   **////**                      ******           /**                              ***   |") ; sleep(0.07)
		print("|  **    //   ******  ********** /**///** **   ** ******  ******  ******   **    **//**   |") ; sleep(0.07)
		print("| /**        **////**//**//**//**/**  /**/**  /**///**/  **////**//**//*  /**   /** /**   |") ; sleep(0.07)
		print("| /**       /**   /** /** /** /**/****** /**  /**  /**  /**   /** /** /   //** /**  /**   |") ; sleep(0.07)
		print("| //**    **/**   /** /** /** /**/**///  /**  /**  /**  /**   /** /**      //****   /**   |") ; sleep(0.07)
		print("|  //****** //******  *** /** /**/**     //******  //** //****** /***       //**    ****  |") ; sleep(0.07)
		print("|   //////   //////  ///  //  // //       //////    //   //////  ///         //    ////   |") ; sleep(0.07)
		print("                                                                      By: Ocean Winckler  |") ; sleep(0.07)
		print(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -")
		print("\033[39m")
	if bool == 1:
		exit()

def output(equation, reduced, degree):
	sleep(0.5)
	print("Equation: " + equation)
	print("Reduced form: ")
	print("Polynominal degree: " + str(degree))
	print("")

class Computor():
	equation = 0
	degree = 0
	arg = 0

	def __init__(self, equation = 0, degree = 0, arg = 0):
		self.equation = equation
		self.degree = degree
		self.arg = arg
		tmp = 0
		sys.argv.pop(0)
		if len((sys.argv)) == 1:
			self.equation = sys.argv[0]
			self.arg = 1
			for i, c in enumerate(self.equation):
				if c.isalpha():
					tmp += int(self.equation[i + 2])
				if c == '+' or c == '-' or c == '*' or c == '=':
					if tmp > degree:
						degree = tmp
					tmp = 0
				if tmp > degree:
					degree = tmp
			self.degree = degree
		else:
			self.equation = "Not enough argument"
			self.arg = -1

computor = Computor();
header(0)
output(computor.equation, 0, computor.degree)
if computor.arg == -1:
	header(1)
header(1)