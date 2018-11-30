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

class Network():
	def __init__(self, shape, activation):
		self.inLayer	= Layer(shape, activation, "input")
		self.layers		= []
		self.outputLayer= None

	# Add a Layer to the Network
	def addLayer(self, shape, activation, type):
		if type == "output":
			self.outputLayer = Layer(shape, activation, type)
		else:
			self.layers.append(Layer(shape, activation, type))

	# Verify and lock the network
	def lock(self):
		# Append output layer else exit()
		if not self.outputLayer:
			ul.outputLogs(red, "Error", "No output layer")
			exit()
		else:
			self.layers.append(self.outputLayer)

		# Initialize weights
		for idx, layer in enumerate(self.layers):
			size = self.layers[idx - 1].shape
			for ind, node in enumerate(layer.nodes):
				self.layers[idx].nodes[ind].weights.append(np.random.uniform(low=0.01, high=0.1, size=size))
			ul.outputLogs(cyan, "Initializing Weights", "Layer " + str(idx + 1))

class Layer():
	def __init__(self, shape, activation, type):
		self.type		= type
		self.activation	= activation
		self.shape		= shape
		self.nodes		= []

		# Create list of node of size shape
		for _ in range(shape):
			self.nodes.append(Node())

		ul.outputLogs(cyan, "Creating Layer", logs="Type: " + type + " | Shape: " + str(shape) + " | Activation: " + activation)

class Node():
	def __init__(self):
		self.weights	= []
		self.value		= 0
		self.error		= 0

# Create Network with on input layer
def createNetwork(shape, activation):
	ul.outputLogs(cyan, "Initializing Neural Network")
	network = Network(shape, activation)
	return network