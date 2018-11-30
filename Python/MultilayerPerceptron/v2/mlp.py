import sys
import pandas as pd
import numpy as np

from YukAi import utils as ul
from YukAi import mlp

M = 0
B =	1

def mlpTrain(dataset):
	def analyseData(file):
		df	= pd.read_csv(file)
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
	network = mlp.createNetwork(1, "sigmoid")
	network.addLayer(2, "sigmoid", "hidden")
	network.addLayer(3, "sigmoid", "hidden")
	network.addLayer(1, "softmax", "output")
	network.lock()

def main(dataset):
	mlpTrain(dataset)

if __name__ == "__main__":
	if len(sys.argv) == 2:
		main(sys.argv[1])
	else:
		print("Dataset not found")