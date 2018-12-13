import pandas as pd
import numpy as np

#======================#
# Activation Functions #
#======================#
SIGMOID = 1
SOFTMAX = 2

def sigmoid(x):
	return 1 / (1 + np.exp(-x))

#================#
# Debug Function #
#================#
def outL(v, d):
	print(v, end=": ")
	print(d)

#======================#
# Neural Network Class #
#======================#
class Network():

	'''
	__init__ will generate weights based
		on the shape of the network
	'''
	def __init__(self, shape, h_active, o_active):
		outL("Shape", shape)
		outL("Hidden Activation", h_active)
		outL("Output Activation", o_active)
		self.shape = shape

		weights = []
		for i in shape[1:]:
			node = []
			for x in range(i):
				node.append(np.random.uniform(0.001, 0.1, shape[i - 1])) # + 1 if bias
			weights.append(node)
		self.weights = weights

	def	_backward_prop(self):
		pass

	def _forward_prop(self):
		pass

	def train(self, data, iteration=3):
		for _ in range(iteration):
			inputs	= np.copy(data)
			inputs	= np.random.shuffle(data)
			inputs	= np.split(inputs, 5, axis=1)
			for x in inputs:
				print(x)