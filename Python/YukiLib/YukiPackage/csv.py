# Get list of headers
def getHead(file):
	with open(file) as f:
		return f.readline().rstrip().split(",")

# Get data from .csv
def getData(file, dtype):
	d = []
	with open(file) as f:
		l = f.read().splitlines()[1:]
	for el in l:
		d.append(el.split(","))
	if dtype == 1:
		dtmp = []
		for idx, el in enumerate(d):
			for ind, el2 in enumerate(el):
				try:
					float(el2)
					dtmp.append(el2)
				except ValueError:
					pass
			d[idx] = dtmp
			dtmp = []
	return d

# Print .csv
# Todo: Beautify
def dataPrint(file, ch, cd, cb):
	h = getHead(file)
	d = getData(file)
	print(cb + "|"),
	for el in h:
		print(ch + el + cb + " |"),
	for el in d:
		print("\r")
		print(cb + "|"),
		for val in el:
			print(cd + val + cb + " |"),