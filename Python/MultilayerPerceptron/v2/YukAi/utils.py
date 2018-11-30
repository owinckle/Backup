import math

def outputLogs(colTitle, title, logs=False):
	white	= "\033[37m"
	print(colTitle + "[" + title + "]", end="")
	if logs:
		print(" " + logs, end="")
	print(white)

def getMax(data, idx):
	maximum = data[idx][0]
	for elem in data[idx]:
		if float(elem) > float(maximum):
			maximum = elem
	return maximum

def getMean(data, idx):
	total, count = 0, 0
	for elem in data[idx]:
		elem = float(elem)
		if elem:
			if math.isnan(elem) == False:
				total += elem
				count += 1
	return total / count

def scaleData(entry, mean, maximum, offset=0):
	for idx in range(offset, len(entry)):
		if math.isnan(float(entry[idx])):
			entry[idx] = mean[idx - offset]
		if maximum[idx - offset] != 0:
			entry[idx] = float(entry[idx]) / maximum[idx - offset]
	return entry