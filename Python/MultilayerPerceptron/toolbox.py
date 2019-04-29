import numpy as np
import os

def FindMaxActivation(output):
	m, index	= output[0], 0

	for i in range(1, len(output)):
		if (output[i] > m):
			m, index = output[i], i
	return index

def Activate(x, activation):
	if (activation == "sigmoid"):
		return Sigmoid(x)
	else:
		return Softmax(x)

def Sigmoid(x):
	return 1 / (1 + np.exp(-x))

def SigmoidDeriative(x):
	return np.multiply(x, 1 - x)

def Softmax(x):
    e_x = np.exp(x - np.max(x))
    return e_x / e_x.sum()

def SaveWeights(weights):
	np.save("saved_weights", weights)
	print("> saving weights './saved_weights.npy'")

def GetWeights():
	try:
		weights = np.load("saved_weights.npy", allow_pickle=True)
		return weights
	except:
		print("No weights have been found, try training the network")
		exit()

def SaveModel():
	user_input	= input("Would you like to save this model ? [y/n]: ")
	if (user_input == "y"):
		system("mv saved_weights.npy saved/{}.npy".format(input("File name: ")))
	else:
		exit()


def Helper():
	print("Useful parameters:")
	print("Use python3 mlp.py <dataset.csv> to pass a dataset to the Network")
	print("  -p	Predict using stored weights or trained weights")
	print("  -t	Train the Neural Network")
	print("  -d	Output Epochs")

def getParams(args):
	debug	= False
	predict	= False
	train	= False
	model	= False

	if "-d" in args:
		debug	= True

	if "-p" in args:
		predict	= True

	if "-t" in args:
		train	= True

	if "-h" in args:
		Helper()

	if "-model" in args:
		if (args.index("-model") + 1):
			model = args.index("-model") + 1

	if not (os.path.isfile(args[1])):
		print("Dataset {} does not exist or can't be accessed".format(args[1]))
		exit()

	return args[1], debug, predict, train, model