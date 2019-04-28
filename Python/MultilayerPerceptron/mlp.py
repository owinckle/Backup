import numpy as np
import pandas as pd
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split
from toolbox import *

def PredictOutput(X, Y, weights):
	correct	= 0

	for i in range(len(X)):
		x, y	= X[i], list(Y[i])
		guess	= Predict(x, weights)

		print(guess)

def Accuracy(X, Y, weights):
	""" Run set through network, find overall accuracy """
	correct	= 0

	for i in range(len(X)):
		x, y	= X[i], list(Y[i])
		guess	= Predict(x, weights)

		if (y == guess):
			# Guessed Correctly
			correct += 1
	return correct / len(X)

def InitializeWeights(nodes):
	""" Initialize Weights with random values in [-1, 1] (including bias)"""
	layers, weights	= len(nodes), []

	for i in range(1, layers):
		w = [[np.random.uniform(-1, 1) for k in range(nodes[i-1] + 1)]
			for j in range(nodes[i])]
		weights.append(np.matrix(w))
	return weights

def ForwardPropagation(x, weights, layers):
	activations, layer_input = [x], x
	for j in range(layers):
		activation	= Sigmoid(np.dot(layer_input, weights[j].T))
		activations.append(activation)
		layer_input	= np.append(1, activation) # Augment with bias
	return activations

def BackwardPropagation(y, activations, weights, layers, lr):
	outputFinal	= activations[-1]
	error		= np.matrix(y - outputFinal) # Error at output

	for j in range(layers, 0, -1):
		currActivation = activations[j]

		if (j > 1):
			# Augment previous activation
			prevActivation = np.append(1, activations[j - 1])
		else:
			# First hidden layer, prevActivation is input (without bias)
			prevActivation = activations[0]
		delta			= np.multiply(error, SigmoidDeriative(currActivation))
		weights[j - 1]	+= lr * np.multiply(delta.T, prevActivation)
		w				= np.delete(weights[j - 1], [0], axis=1) # Remove bias frm weights
		error			= np.dot(delta, w) # Calculate error for current layer
	return weights

def Train(X, Y, lr, weights):
	layers	= len(weights)

	for i in range(len(X)):
		x, y		= X[i], Y[i]
		x			= np.matrix(np.append(1, x)) # Augment feature vector

		activations	= ForwardPropagation(x, weights, layers)
		weights		= BackwardPropagation(y, activations, weights, layers, lr)
	return weights 

def Predict(item, weights):
	layers		= len(weights)
	item		= np.append(1, item) # Augment feature vector

	##_Forward Propagation_##
	activations = ForwardPropagation(item, weights, layers)

	outputFinal	= activations[-1].A1
	index		= FindMaxActivation(outputFinal)

	# Initialize prediction vector to zeros
	y			= [0 for i in range(len(outputFinal))]
	y[index]	= 1 # Set guessed class to 1

	return y # Return prediction vector

def NeuralNetwork(X_train, Y_train, X_val=None, Y_val=None, epochs=10, nodes=[], lr=0.15):
	hidden_layers	= len(nodes) - 1
	weights			= InitializeWeights(nodes)

	for epoch in range(1, epochs + 1):
		weights	= Train(X_train, Y_train, lr, weights)

		if (epoch % 20 == 0):
			print("Epoch {}".format(epoch))
			print("Training Accuracy: {}".format(Accuracy(X_train, Y_train, weights)))
			if X_val.any():
				print("Validation Accuracy: {}".format(Accuracy(X_val, Y_val, weights)))
	return weights

def main():
	iris	= pd.read_csv("data/iris.csv")
	# iris	= iris.sample(frac=1).reset_index(drop=True) # Shuffle
	X		= iris[["SepalLengthCm", "SepalWidthCm", "PetalLengthCm", "PetalWidthCm"]]
	X		= np.array(X)

	ohe		= OneHotEncoder(sparse=False)
	Y		= iris.Species
	Y		= ohe.fit_transform(np.array(Y).reshape(-1, 1))

	X_train, X_test, Y_train, Y_test	= train_test_split(X, Y, test_size=0.15)
	X_train, X_val, Y_train, Y_val		= train_test_split(X_train, Y_train, test_size=0.1)

	f		= len(X[0]) # Number of features
	o		= len(Y[0]) # Number of outputs / classes

	layers	= [f, 5, 10, o] # Number of nodes in layers
	lr		= 0.15
	epochs	= 100

	weights	= NeuralNetwork(X_train, Y_train, X_val, Y_val, epochs=epochs, nodes=layers, lr=lr)
	print("Testing Accuracy: {}".format(Accuracy(X_test, Y_test, weights)))
	PredictOutput(X, Y, weights)

if __name__ == "__main__":
	main()