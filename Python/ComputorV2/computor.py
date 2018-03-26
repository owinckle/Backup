from sys import argv
import os
import re

l_exit = ["exit", "quit", "close"]
mat_reg = [",,", ";;"]
user = argv[1]
variables = {}

def terminate(msg):
	print(msg)
	exit(1)

def commands(line):
	if line in l_exit:
		terminate("\033[31mExiting Computor.\033[39m")
	elif line == "clear":
		os.system("clear")
		print("\033[32m\n" + user + "> \033[39m" + line)
		return "Console cleared"
	return False

def isdecimal(n):
	if n.count(".") == 1:
		if n.split(".")[0].isdigit() and n.split(".")[1].isdigit():
			return True
	return False

def mathParse(split):
	for i, c in enumerate(split):
		if c.isalpha():
			try:
				split[i] = variables[c]
			except KeyError:
				split[i] = "0"
	return(split)

def mathSimple(split, i):
	split = split[0:i - 2]
	result = 0
	first = True
	split = mathParse(split)
	for i2, c in enumerate(split):
		if c == "*":
			if first == True:
				result = float(split[i2 - 1]) * float(split[i2 + 1])
				first = False
			else:
				result = result * float(split[i2 + 1])
		elif c == "/":
			if first == True:
				result = float(split[i2 - 1]) / float(split[i2 + 1])
				first = False
			else:
				result = result / float(split[i2 + 1])
	for i2, c in enumerate(split):
		if c == "+":
			if first == True:
				result = float(split[i2 - 1]) + float(split[i2 + 1])
				first = False
			else:
				result = result + float(split[i2 + 1])
		elif c == "-":
			if first == True:
				result = float(split[i2 - 1]) - float(split[i2 + 1])
				first = False
			else:
				result = result - float(split[i2 + 1])
	if str(result).split(".")[1] == "0":
		result = int(result)	
	return(str(result))

def matrixAssign(split, var):
	if split.count("[") != split.count("]"):
		return False
	for c in mat_reg:
		if c in split:
			return False
	split = split[1:len(split) - 1].replace(";", "\n")
	variables[var] = "Matrix:\n" + split
	return (variables[var])


def varPrint(split):
	if split[0].isalpha():
		try:
			variables[split[0]]
			return(variables[split[0]])
		except KeyError:
			return("0")
	if split[0].isdigit():
		return(split[0])
	if isdecimal(split[0]):
		return(split[0])

def varAssign(split):
	try:
		split[3]
		variables[split[0]] = computor.compute(" ".join(split[2:]) + " = ?")
	except IndexError:
		try:
			if split[2].isdigit():
				variables[split[0]] = split[2]
			elif split[2].isalpha():
				try:
					variables[split[0]] = variables[split[2]]
				except KeyError:
					variables[split[0]] = "0"
			elif split[2] == "?":
				try:
					return(variables[split[0]])
				except KeyError:
					return("0")
			elif split[2][0] == "[":
				return (matrixAssign(split[2], split[0]))
			else:
				if isdecimal(split[2]):
					variables[split[0]] = split[2]
					return(split[2])
				return False
		except IndexError:
			return False
	return(variables[split[0]])

class Computor():
	output = ""
	variables = []

	def __init__(self):
		self.output = ""
		self.variables = []

	def compute(self, line):
		if commands(line):
			return(line + " executed")
		split = line.split()
		i = len(split)
		if i == 1:
			return(varPrint(split))
		elif i > 1:
			if split[1] == "=":
				if split[0].isalpha():
					return(varAssign(split))
			if split[i - 2:] == ["=", "?"]:
				return(mathSimple(split, i))
		return False

computor = Computor()
if len(argv) != 2:
	terminate("\033[31mUsage: python computor.py [username]\033[39m")
while 42:
	try:
		line = raw_input("\033[32m\n" + user + "> \033[39m")
		output = computor.compute(line)
		if not output:
			print("\033[91mComputor>\033[39m Syntax Error")
			continue
		else:
			print("\033[91mComputor>\033[39m " + output)
	except KeyboardInterrupt:
		print("(interrupt) Exiting Computor")
		exit(1)
