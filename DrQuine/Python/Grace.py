# c1

def print_source(f, s):
	f.write(s.format(s = s, q = chr(34)))

def ft(x):
	if __name__ == '__main__':
		try:
			f = open('Grace_kid.py', 'w')
			print_source(f, x)
		except:
			exit(1)

source = """# c1

def print_source(f, s):
	f.write(s.format(s = s, q = chr(34)))

def ft(x):
	if __name__ == '__main__':
		try:
			f = open('Grace_kid.py', 'w')
			print_source(f, x)
		except:
			exit(1)

source = {q}{q}{q}{s}{q}{q}{q}

ft(source)
"""

ft(source)
