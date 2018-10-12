import matplotlib.pyplot as plt
import sys
import YukiPackage.csv as ypcsv
import YukiPackage.stats as ypstats
import YukiPackage.lists as ypl

FILE = 'data/dataset_train.csv'

def histogram(file):
	def splitHouses(features):
		Gryffindor	= []
		Hufflepuff	= []
		Ravenclaw	= []
		Slytherin	= []

		for val in features:
			if val[:val.index(":")] == "Gryffindor":
				Gryffindor.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == "Hufflepuff":
				Hufflepuff.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == "Ravenclaw":
				Ravenclaw.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == "Slytherin":
				Slytherin.append(val[val.index(":") + 1:])
		return Gryffindor, Hufflepuff, Ravenclaw, Slytherin

	features = []
	header = ypcsv.getHead(file)
	d = ypcsv.getData(file, 1)
	f, header = ypl.cleanList(d, header, "NaN")
	d = ypcsv.getData(file, 0)
	del header[0]
	for l in f:
		del l[0]
	for c in range(0, len(header), +1):
		for ind, df in enumerate(f):
			for entry in enumerate(d):
				df[c] = d[ind][1] + ":" + str("%.f" % float(df[c]))
				break
	for c in range(0, len(header), +1):
		features.append([x[c] for x in f])
	for idx, h in enumerate(header):
		# features[idx] = ypl.delEl([x[x.index(":") + 1:] for x in features[idx]], "nan")
		plt.hist(splitHouses(features[idx]), bins=20, alpha=0.8, histtype='stepfilled',
			rwidth="0.8", color=["red", "yellow", "blue", "green"], label=["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"])
		plt.title(h)
		plt.show()

def main():
	f = FILE if len(sys.argv) != 2 else sys.argv[1]
	histogram(f)

if __name__ == '__main__':
	main()