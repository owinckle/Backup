import sys
import pandas as pd
import numpy as np

from YukAi import utils as ul
from YukAi import mlp

# Color variables
black	= "\033[30m"
red		= "\033[31m"
green	= "\033[32m"
yellow	= "\033[33m"
blue	= "\033[34m"
purple	= "\033[35m"
cyan	= "\033[36m"
white	= "\033[37m"

# Output variables
M = 0
B =	1

def mlpTrain(dataset):
	def analyseData(file):
		try:
			df	= pd.read_csv(file)
		except FileNotFoundError:
			ul.outputLogs(red, "Error", "Dataset does not exist")
			exit()
		df.loc[-1] = df.columns.values
		df.index = df.index + 1
		df = df.sort_index()
		df.columns = range(0 - 1, len(df.columns) - 1)
		df	= df.replace({'M': 0}, regex=True)
		df	= df.replace({'B': 1}, regex=True)
		df	= df.drop(df.columns[0], axis=1)
		fc	= len(df.columns)
		return df, fc

	# Get Dataset
	data, input_shape = analyseData(dataset)
	dataArr = np.array(data)

	# Scale Data
	maximum = []
	mean	= []
	for idx in range(1, input_shape):
		maximum.append(ul.getMax(data, idx))
		mean.append(ul.getMean(data, idx))
	for idx, entry in enumerate(dataArr):
		dataArr[idx] = ul.scaleData(entry, mean, maximum, offset=1)

	# Create Network
	network = mlp.createNetwork(input_shape, "sigmoid")
	network.addLayer(30, "sigmoid", "hidden")
	network.addLayer(30, "sigmoid", "hidden")
	network.addLayer(1, "sigmoid", "output")
	network.lock()
	network.train(dataArr, lr=0.5, iteration=50)

def main(dataset):
	mlpTrain(dataset)

if __name__ == "__main__":
	if len(sys.argv) == 2:
		main(sys.argv[1])
	else:
		print("Dataset not found")