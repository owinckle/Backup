import pandas as pd
import numpy as np
import sys

def getData(dataset):
	return np.array(pd.read_csv(dataset))

def saveThetas(thetas):
	df = pd.DataFrame(thetas)
	df.to_csv("thetas.csv",  index=False)

def scaleData(data, _max):
	for idx, x in enumerate(data):
		data[idx][0] /= _max[0]
		data[idx][1] /= _max[1]
	return data

def estimate(t0, t1, x):
	return (t0 + (t1 * x))

def sumt0(t0, t1, data, m):
	total = 0.

	for val in data:
		total += estimate(t0, t1, val[0]) - val[1]
	return total

def sumt1(t0, t1, data, m):
	total = 0.

	for val in data:
		total += (estimate(t0, t1, val[0]) - val[1]) * val[0]
	return total

def main(dataset):
	data	= getData(dataset)
	m		= len(data)
	_max	= [max(data[:,0]), max(data[:,1])]
	data	= scaleData(data.astype(float), _max)
	lr		= 0.9
	iterate	= 200
	thetas	= [0., 0.]
	tmp		= [1., 1.]

	for i in range(iterate):
		tmp[0]		= lr * (1 / m) * sumt0(thetas[0], thetas[1], data, m)
		tmp[1]		= lr * (1 / m) * sumt1(thetas[0], thetas[1], data, m)  
		thetas[0]	-= tmp[0]
		thetas[1]	-= tmp[1]
	saveThetas(thetas)

if __name__ == "__main__":
	f = "data.csv"
	main(f)