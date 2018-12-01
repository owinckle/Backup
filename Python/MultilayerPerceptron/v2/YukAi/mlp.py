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

LAYER_TYPE = ["hidden", "output"]

'''
Dataset Template
Index 0		: Desired output
Index 1+	: Data
'''

# Network Class
class Network():
	def __init__(self, shape, activation):
		self.inLayer	= Layer(shape - 1, activation, "input")
		self.layers		= []
		self.outputLayer= None
		self.locked		= False

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
			# Check layer type
			if not layer.type in LAYER_TYPE:
				ul.outputLogs(red, "Error", "Unknown layer type: " + layer.type)
				exit()

			size = self.layers[idx - 1].shape
			if idx == 0:
				size = self.inLayer.shape
			for ind, node in enumerate(layer.nodes):
				self.layers[idx].nodes[ind].weights = (np.random.uniform(low=0.01, high=0.1, size=size))
			ul.outputLogs(cyan, "Initializing Weights", "Layer " + str(idx + 1))

		self.locked = True
		ul.outputLogs(green, "Locked", "Network is ready for training")

	# Activated a neuron using weights, biases and activation functions
	def activate_node(self, layer_id, node_id):
		# Set input layer
		inputL = self.inLayer if layer_id == 0 else self.layers[layer_id - 1]

		# Get Weights
		weights = self.layers[layer_id].nodes[node_id].weights

		# Set activation function
		activation = ul.sigmoid if self.layers[layer_id].activation == "sigmoid" else ul.softmax

		# Activate neuron
		nodeValue = 0.
		for idx, inputN in enumerate(inputL.nodes):
			nodeValue += inputN.value * weights[idx]
		self.layers[layer_id].nodes[node_id].value = activation(nodeValue)

	# Forward Propagation
	def forwardP(self):
		for idx, layers in enumerate(self.layers):
			for ind, node in enumerate(layers.nodes):
				self.activate_node(idx, ind)
		print(self.layers[2].nodes[0].value)

	# Train Network
	def train(self, input_data, iteration=3):
		if not self.locked:
			ul.outputLogs(red, "Error", "Please lock the network before training")
		# Iterate
		for i in range(iteration):
			# For each entry, set it to input layer neurones
			for data in input_data:
				self.desired = data[0]
				for idx, node in enumerate(self.inLayer.nodes):
					node.value = data[idx + 1]
				self.forwardP()

# Layer Class
class Layer():
	def __init__(self,shape, activation, type):
		self.type		= type
		self.activation	= activation
		self.shape		= shape
		self.nodes		= []

		# Create list of node of size shape
		for _ in range(shape):
			self.nodes.append(Node())

		ul.outputLogs(cyan, "Creating Layer", logs="Type: " + type + " | Shape: " + str(shape) + " | Activation: " + activation)

# Node Class
class Node():
	def __init__(self):
		self.weights	= []
		self.value		= 0
		self.error		= 0

# Create Network with on input layer
def createNetwork(shape, activation):
	ul.outputLogs(green, "Initializing Neural Network")
	network = Network(shape, activation)
	return network