import numpy as np

def FindMaxActivation(output):
	""" Find max activation in output """
	m, index	= output[0], 0

	for i in range(1, len(output)):
		if (output[i] > m):
			m, index = output[i], i
	return index

def Sigmoid(x):
	return 1 / (1 + np.exp(-x))

def SigmoidDeriative(x):
	return np.multiply(x, 1 - x)