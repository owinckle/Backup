import numpy as np
import pandas as pd
import sys

FILE	= "data/dataset_train.csv"
HOUSES	= ["Gryffindor", "Slytherin", "Ravenclaw", "Hufflepuff"]
CLASS	= "Hogwarts House"
IGNORED = ["Arithmancy", "Astronomy", "Ancient Runes", "Transfiguration", "Potions", "Care of Magical Creatures"]

def saveThetas(theta):
	df = pd.DataFrame(theta, columns=range(0,8))
	df.to_csv("thetas.csv", index=False)

def getMax(data, idx):
	maximum = data[0][idx]
	for elem in data:
		if elem[idx] and elem[idx] > maximum:
			maximum = elem[idx]
	return maximum

def NaNtoMean(data):
	y = []
	nbStuds = data[CLASS].value_counts()
	for idx, label in enumerate(data.columns[1:]):
		meanG = data.loc[data[CLASS] == HOUSES[0], label].sum() / float(nbStuds[HOUSES[0]])
		meanR = data.loc[data[CLASS] == HOUSES[1], label].sum() / float(nbStuds[HOUSES[1]])
		meanS = data.loc[data[CLASS] == HOUSES[2], label].sum() / float(nbStuds[HOUSES[2]])
		meanH = data.loc[data[CLASS] == HOUSES[3], label].sum() / float(nbStuds[HOUSES[3]])
		for ind, cell in enumerate(data[label]):
			if pd.isna(cell):
				house = data.iat[ind, 0]
				if house == HOUSES[0]:
					data.iat[ind, idx + 1] = meanG
				elif house == HOUSES[1]:
					data.iat[ind, idx + 1] = meanR
				elif house == HOUSES[2]:
					data.iat[ind, idx + 1] = meanS
				else:
					data.iat[ind, idx + 1] = meanH
	return data

def scaleData(data, n, maximum):
	for idx in range(n):
		if maximum[idx] != 0:
			data[idx] /= maximum[idx]
	return data

def getDataset(file):
	df = pd.read_csv(file)
	
	for label in df.columns[:6]:
		if not label == CLASS:
			df = df.drop(label, axis=1)
	for label in IGNORED:
		df = df.drop(label, axis=1)
	df = NaNtoMean(df)
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

def hypothesis(theta, x):

	z = sum([theta[i] * x[i] for i in range(len(x))])
	return 1.0 / (1.0 + np.e ** -z)

def gradient(data, _map, obs, n, iteration=0, lr=3.0):
	theta = [[0.0 for a in range(n)] for b in range(4)]
	for _ in range(iteration):
		for house in range(4):
			sums = [0.] * n
			for idx in range(obs):
				for ind in range(n):
					sums[ind] += (hypothesis(theta[house], data[idx]) - (_map[idx] == house)) * data[idx][ind]
			for idx in range(n):
				theta[house][idx] -= (lr / obs) * sums[idx]
	return theta

def main():
	data, _map	= getDataset(FILE if len(sys.argv) != 2 else sys.argv[1])
	theta		= [[] for i in range(4)]
	obs			= len(data)
	n			= len(data[0])
	maximum		= []
	mean		= []

	for idx in range(n):
		maximum.append(getMax(data, idx))
	for idx in range(obs):
		data[idx] = scaleData(data[idx], n, maximum)
	theta = gradient(data, _map, obs, n, iteration=3)
	saveThetas(theta)

if __name__ == "__main__":
	main()




















