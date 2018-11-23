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

	def think(self,*args,  data, lr):
		weights = []
		for x in range(1, self.size):
			weights.append(np.random.uniform(low=0.01, high=0.1, size=self.layers[x].shape))

		lay1 = data
		for dl in range(1, self.size):
			lay2 = np.zeros(self.layers[dl].shape)
			for idx, y in enumerate(lay2):
				for x in lay1:
					lay2[idx] += x * weights[dl - 1][idx]
				lay2[idx] = self.activate(dl, lay2[idx])
			lay1 = lay2
		self.output = lay1
		print(args)
		print(self.output)

class DenseLayer():
	def __init__(self, shape, activation, type):
		self.shape		= shape
		self.activation	= activation
		self.type		= type

def createNetwork(*args):
	print(cyan + "[Initializing Neural Network of " + str(len(args)) + " layers] - ", end="")

	network = Network(layers=args)
	if network.error > 0:
		print(red + "Failed\nError in createNetwork() from YukAi, invalid layers\nCode: " + str(network.error) + white)
		exit(network.error)

	print(green + "Success" + white)
	return network