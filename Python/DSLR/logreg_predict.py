import numpy as np
import pandas as pd
import sys
import math

FILE	= "data/dataset_test.csv"
THETAS	= "thetas.csv"
HOUSES	= ["Gryffindor", "Slytherin", "Ravenclaw", "Hufflepuff"]
CLASS	= "Hogwarts House"
IGNORED = ["Arithmancy", "Astronomy", "Ancient Runes", "Transfiguration", "Potions", "Care of Magical Creatures"]

def getMax(data, idx):
	maximum = data[0][idx]
	for elem in data:
		if elem[idx] and elem[idx] > maximum:
			maximum = elem[idx]
	return maximum

def getMean(data, i):
	total, count = 0, 0
	for elem in data:
		if elem[i]:
			if math.isnan(elem[i]) == False:
				total += elem[i]
				count += 1
	return total / count

def scaleData(data, n, mean, maximum, t):
	for idx in range(n):
		if math.isnan(data[idx]):
			data[idx] = mean[idx]
		if maximum[idx] != 0:
			data[idx] /= maximum[idx]
	return data

def getThetas():
	df = pd.read_csv(THETAS)
	thetas = df.values.tolist()
	return thetas

def getDataset(file):
	df = pd.read_csv(file)
	
	for label in df.columns[:6]:
		if not label == CLASS:
			df = df.drop(label, axis=1)
	for label in IGNORED:
		df = df.drop(label, axis=1)
	features, _map = [], []
	for row in df.values:
		if row[0] == HOUSES[0]:
			_map.append(0)
		elif row[0] == HOUSES[1]:
			_map.append(1)
		elif row[0] == HOUSES[2]:
			_map.append(2)
		else:
			_map.append(3)
		row[0] = 1
		features.append(row)
	return(np.array(features), np.array(_map))

def sigmoid(theta, data):
	z = sum([theta[idx] * data[idx] for idx in range(len(data))])
	return 1.0 / (1.0 + np.e ** -z)

def predict(thetas, data):
	val = [sigmoid(th, data) for th in thetas]
	idx =  val.index(max(val))
	return (HOUSES[idx])

def getPredictions(thetas, data, obs):
	output = []
	for idx in range(obs):
		output.append([str(idx), predict(thetas, data[idx])])
	df = pd.DataFrame(output, columns=["Index", "House"])
	df.to_csv("houses.csv", index=False)

def main():
	data, _map	= getDataset(FILE if len(sys.argv) != 2 else sys.argv[1])
	theta		= [[] for i in range(4)]
	obs			= len(data)
	n			= len(data[0])
	maximum		= []
	mean		= []
	thetas		= getThetas()

	data = np.array(data)
	for idx in range(n):
		maximum.append(getMax(data, idx))
		mean.append(getMean(data, idx))
	for idx in range(obs):
		data[idx] = scaleData(data[idx], n, mean, maximum, idx)
	getPredictions(thetas, data, obs)

if __name__ == "__main__":
	main()




















