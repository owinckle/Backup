import sys

import numpy as np
import pandas as pd

from YukAi import mlp
from YukAi import utils as ul

M = [1., 0.]
B =	[0., 1.]

def mlpTrain(file):
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
		obs	= len(df)
		return df, fc, obs

	data, input_shape, obs = analyseData(file)
	dataArr = np.array(data)
	maximum = []
	mean	= []
	for idx in range(1, input_shape):
		maximum.append(ul.getMax(data, idx))
		mean.append(ul.getMean(data, idx))
	for idx, entry in enumerate(dataArr):
		dataArr[idx] = ul.scaleData(entry, mean, maximum, offset=1)

	network = mlp.createNetwork(
		mlp.DenseLayer(shape=input_shape, activation="sigmoid", type="input"),
		mlp.DenseLayer(shape=3, activation="sigmoid", type="hidden"),
		mlp.DenseLayer(shape=3, activation="sigmoid", type="hidden"),
		mlp.DenseLayer(shape=1, activation="softmax", type="output")
		)
	for entry in dataArr:
		network.think(entry[0], data=entry)

def main(args):
	dataset = ""
	predict = ""
	try:
		if "--dataset" in args:
			dataset = args[args.index("--dataset") + 1]
		if "--predict" in args:
			predict = args[args.index("--predict") + 1]
	except IndexError:
		print("Invalid File")
		exit()
	if predict == "":
		mlpTrain(dataset)

if __name__ == "__main__":
	main(sys.argv)