import matplotlib.pyplot as plt
import sys
import YukiPackage.csv as ypcsv
import YukiPackage.stats as ypstats
import YukiPackage.lists as ypl
import numpy as np

FILE = 'data/dataset_train.csv'
HOUSES = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]
COLORS = ["red", "yellow", "blue", "green"]

def histogram(file):
	def splitHouses(features):
		Gryffindor	= []
		Hufflepuff	= []
		Ravenclaw	= []
		Slytherin	= []

		for val in features:
			if val[:val.index(":")] == HOUSES[0]:
				Gryffindor.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == HOUSES[1]:
				Hufflepuff.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == HOUSES[2]:
				Ravenclaw.append(val[val.index(":") + 1:])
			elif val[:val.index(":")] == HOUSES[3]:
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
		histoArray = []	
		for arr in splitHouses(features[idx]):
			histoArray.append(np.array(arr, dtype="float"))
		histoArray = [arr[~np.isnan(arr)] for arr in histoArray]
		plt.plot(histoArray, bins=20, alpha=0.8, histtype='stepfilled', color=COLORS, label=HOUSES)
		plt.legend()
		plt.title(h)
		plt.show()

def main():
	f = FILE if len(sys.argv) != 2 else sys.argv[1]
	histogram(f)

if __name__ == '__main__':
	main()