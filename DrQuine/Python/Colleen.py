# This program will print its own source when run.

def print_source(source):
	print(source.format(s = source, q = chr(34)))

if __name__ == '__main__':
	# Comment.
	source = """# This program will print its own source when run.

def print_source(source):
	print(source.format(s = source, q = chr(34)))

if __name__ == '__main__':
	# Comment.
	source = {q}{q}{q}{s}{q}{q}{q}
	print_source(source)"""
	print_source(source)
