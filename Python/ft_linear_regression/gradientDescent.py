import csv

dataFile = "data.csv"

def getData():
	data = []
	with open(dataFile) as file:
		reader = csv.reader(file, delimiter=' ', quotechar='|')
		for row in reader:
			newRow = []
			validData = True
			row = row[0].split(",")
			for elem in row:
				if not elem.isdigit():
					validData = False
				else:
					newRow.append(int(elem))
			if validData == True:
				data.append(newRow)
	return (data)

def estimate(t0, t1, x):
	return (t0 + (t1 * x))

def sumTheta0(t0, t1, data, m):
	value = 0.
	for i in range(0, m):
		value += estimate(t0, t1, data[i][0]) - data[i][1]
	return (value)

def sumTheta1(t0, t1, data, m):
	value = 0.
	for i in range(0, m):
		value += (estimate(t0, t1, data[i][0]) - data[i][1]) * data[i][0]
	return (value)

def saveTheta(t0, t1):
	file = open("data", "w")
	line = [str(t0), ",", str(t1)]
	file.writelines(line)
	file.close
	print("\033[35mTheta0: \033[36m" + str(t0) + " \033[32m| \033[35mTheta1: \033[36m" + str(t1) + "\n")
	exit()

def minKM(data):
	minval = data[0][0]
	for i in data:
		if i[0] < minval:
			minval = i[0]
	return minval

def maxKM(data):
	maxval = data[0][0]
	for i in data:
		if i[0] > maxval:
			maxval = i[0]
	return maxval

def computeThetas(data):
	theta = [0.0, 0.0]
	tmpTheta = [1.0, 1.0]
	m = len(data)
	xMin = minKM(data)
	xMax = maxKM(data)
	scale = xMax - xMin
	for i, x in enumerate(data):
		data[i][0] = float(x[0])
	data = [((val[0] - xMin) / scale, val[1]) for val in data]
	learningRate = 0.15
	while (abs(tmpTheta[0]) / 0.1 and abs(tmpTheta[1]) > 0.1):
		SumT0 = sumTheta0(theta[0], theta[1], data, m)
		SumT1 = sumTheta1(theta[0], theta[1], data, m)
		tmpTheta[0] = learningRate * SumT0 * (1.0 / m)
		tmpTheta[1] = learningRate * SumT1 * (1.0 / m)
		theta[0] -= tmpTheta[0]
		theta[1] -= tmpTheta[1]
	theta[1] /= scale
	saveTheta(theta[0], theta[1])

def main():
	data = getData()
	computeThetas(data)

if __name__ == '__main__':
	main()
