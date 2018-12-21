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
		self.h_active = np.vectorize(sigmoid)
		# self.o_active = np.vectorize(softmax)

		weights = []
		for i in shape[1:]:
			node = []
			for x in range(i):
				node.append(np.random.uniform(0.001, 0.1, shape[i - 1])) # + 1 if bias
			weights.append(node)
		self.weights = weights

	def	_backward_prop(self):
		pass

	def _forward_prop(self, inputs):
		results	= []
		results.append(inputs)
		for idx in range(len(self.shape) - 1):
			results.append(np.dot(results[idx], self.weights[idx]))

	def train(self, data, iteration=3):
		np.random.seed(1)

		for _ in range(iteration):
			inputs	= np.copy(data)
			# np.random.shuffle(inputs)
			inputs	= np.split(np.transpose(inputs), 5, axis=1)
			exp		= np.concatenate(np.array(inputs[:1])[0])
			for idx, x in enumerate(inputs):
				inputs[idx] = np.delete(x, (0), axis=0)
			for batch in inputs:
				self._forward_prop(batch)
			