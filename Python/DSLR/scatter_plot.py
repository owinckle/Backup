import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sb
import sys
import numpy as np

HOUSES = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]
COLORS = ["#4741f4", "#12aa17", "#af0e0e", "#d7f210"]
FILE = "data/dataset_train.csv"

def pair_plot(f):
	data = pd.read_csv(f)
	labels = pd.read_csv(f, nrows=1).columns[6:]
	data = data.dropna()
	for f in labels:
		feature = [x for x in data[f]]
		feature.sort()
		plt.scatter(feature, np.arange(len(feature)), s=3.)
		plt.xlabel(f)
		plt.ylabel("Index")
		plt.show()

def main():
	f = FILE if len(sys.argv) != 2 else sys.argv[1]
	pair_plot(f)

if __name__ == '__main__':
	main()
