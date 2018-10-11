import sys
import YukiPackage.csv as ypcsv
import YukiPackage.stats as ypstats
import YukiPackage.lists as ypl
import YukiPackage.colors as ycol
import datascience as ds

FIELDS = ["Count", "Mean", "Std", "Min", "25%", "50%", "75%", "Max"]

def describe(file):
	def analyze(arr):
		c	= len(arr)
		m	= ypstats.mean(arr)
		s	= ypstats.std(arr)
		mn	= arr[0]
		p1	= ypstats.percentile(arr, 25)
		p2	= ypstats.percentile(arr, 50)
		p3	= ypstats.percentile(arr, 75)
		mx	= arr[c - 1]
		return c, m, s, mn, p1, p2, p3, mx

	def calculate(data):
		rslt = []
		for feature in data:
			for el in feature:
				rslt.append(analyze(sorted(el, key=float)))
		return rslt

	def sortData(data):
		featureList = []
		features = [[] for x in range(len(data[0]))]
		for el in data:
			for idx, val in enumerate(el):
				if idx < len(data[0]) and val != "NaN":
					features[idx].insert(len(features[idx]), val)
		featureList.append(features)
		return featureList

	def display(rslt):
		tab = ds.Table(["______"] + header)
		for c in range(0, 8, +1):
			t = [x[c] for x in rslt]
			t.insert(0, FIELDS[c])
			tab.append(t)
		print(tab)

	header = ypcsv.getHead(file)
	data = ypcsv.getData(file, 1)
	data, header = ypl.cleanList(data, header, "NaN")
	data = sortData(data)
	rslt = calculate(data)
	display(rslt)

def main():
	if len(sys.argv) != 2:
		exit("Usage: py describe.py [data_file.csv]")
	describe(sys.argv[1])

if __name__ == "__main__":
	main()