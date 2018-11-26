import numpy as np
from YukAi import utils as ul

# Color variables
black	= "\033[30m"
red		= "\033[31m"
green	= "\033[32m"
yellow	= "\033[33m"
blue	= "\033[34m"
purple	= "\033[35m"
cyan	= "\033[36m"
white	= "\033[37m"

# Globals
LAYER_TYPE	= ["input", "hidden", "output"]

class Network():
	def __init__(self, layers):
		self.layers = layers
		self.size	= len(layers)
		self.error	= 0
		cin			= False
		cout		= False
		errType		= False
		np.random.seed(0)

		for idx in range(0, self.size):
			lType = layers[idx].type
			if lType == "input":
				if cin == True:
					self.error = 1
				cin = True
			if lType == "output":
				if cout == True:
					self.error = 2
				cout = True
			if not lType in LAYER_TYPE:
				errType = True
		if cin == False:
			self.error = 1
		if cout == False:
			self.error = 2
		if errType == True:
			self.error = 3

	def activate(self, layerId, value):
		if self.layers[layerId].activation == "sigmoid":
			return ul.sigmoid(value)
		elif self.layers[layerId].activation == "softmax":
			return ul.softmax(value)
		else:
			print(red + "Error from YukAi, unknown activation function" + white)
			exit()

	def back(self, desired):
		for idx in reversed(range(1, self.size)):
			errors = []
			if self.layers[idx].type == "output":
				errors.append(desired - self.output)
			elif self.layers[idx].type == "hidden":
				for j in range(self.layers[idx].shape):
					error = 0.0
					for n_id in range(self.layers[idx + 1].shape):
						error += (self.layers[idx + 1].weights[n_id][j] * self.layers[idx + 1].error[n_id])
					errors.append(error)
			for j in range(self.layers[idx].shape):
				self.layers[idx].error[j] = errors[j] * ul.derivative_function(-self.layers[idx].nodes[j]) # oO Nothing happens without that which is tragic
			print(errors)

	def think(self, *args,  data, lr=0.1, predict=False):
		for x in range(1, self.size):
			self.layers[x]._init_weights(self.layers[x - 1].shape)

		lay1 = data
		for idx in range(1, self.size):
			lay2 = np.zeros(self.layers[idx].shape)
			for ind, j in enumerate(lay2):
				for node_id, x in enumerate(lay1):
					lay2[ind] += (x * self.layers[idx].weights[ind][node_id])
				lay2[ind] = self.activate(idx, lay2[ind])
			self.layers[idx].nodes = lay2
			lay1 = lay2
		self.output = lay1
		if predict == True:
			pass
		elif predict == False:
			self.back(args[0])

class DenseLayer():
	def __init__(self, shape, activation, type):
		self.shape		= shape
		self.activation	= activation
		self.type		= type
		self.nodes		= []
		self.error		= np.zeros(self.shape)

	def _init_weights(self, n_nodes):
		self.weights = []
		for x in range(self.shape):
			self.weights.append(np.random.uniform(low=0.01, high=0.1, size=n_nodes))

def createNetwork(*args):
	print(cyan + "[Initializing Neural Network of " + str(len(args) - 1) + " layers] - ", end="")

	network = Network(layers=args)
	if network.error > 0:
		print(red + "Failed\nError in createNetwork() from YukAi, invalid layers\nCode: " + str(network.error) + white)
		exit(network.error)

	print(green + "Success" + white)
	return network