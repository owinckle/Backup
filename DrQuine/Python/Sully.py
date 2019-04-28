from os import system

def file(x):
	return 'Sully_' + str(i) + '.py'

def print_source(f, s, i):
	f.write(s.format(s = s, q = chr(34), i = i))

source = """from os import system

def file(x):
	return 'Sully_' + str(i) + '.py'

def print_source(f, s, i):
	f.write(s.format(s = s, q = chr(34), i = i))

source = {q}{q}{q}{s}{q}{q}{q}

i = {i}

try:
	with open(file(i), 'w') as f:
		print_source(f, source, i - 1)
except:
	exit(1)
if i > 0:
	system('python ' + file(i))
"""

i = 5

try:
	with open(file(i), 'w') as f:
		print_source(f, source, i - 1)
except:
	exit(1)
if i > 0:
	system('python ' + file(i))