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
		if not self.outputLayer:
			print(red + "Error, no output layer" + white)
			exit()
		self.layers.append(self.outputLayer)

class Layer():
	def __init__(self, shape, activation, type):
		self.type		= type
		self.activation	= activation
		self.shape		= shape
		self.nodes		= []

		print(cyan + "[Creating Layer] Type: " + type + " | Shape: " + str(shape) + " | Activation: " + activation + white)

class Node():
	def __init__(self):
		self.weights	= []
		self.value		= []
		self.error		= 0

# Create Network with on input layer
def createNetwork(shape, activation):
	print(cyan + "[Initializing Neural Network]")

	network = Network(shape, activation)
	return network