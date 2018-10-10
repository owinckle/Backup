"""
Simplistic implementation of the two-layer neural network.
Training method is stochastic (online) gradient descent with momentum.
As an example it computes XOR for given input.
Some details:
- tanh activation for hidden layer
- sigmoid activation for output layer
- cross-entropy loss
"""

import numpy as np
import time

# Variables
n_hidden	= 10
n_input		= 10
n_output	= 10	# Outputs
n_sample	= 300	# Sample Data

# Hyper Parameters
learning_rate	= 0.01
momentum		= 0.9

# Non deterministic seeding
np.random.seed(0)

# Activation functions
def sigmoid(x):
	return 1.0 / (1 + np.exp(-x))

def tanh_prime(x):
	return 1 - np.tanh(x) ** 2

# Training function
# x : Input Data
# t : Transpose
# V : Layer 1
# W : Layer 2
# bv: Bias V
# bw: Bias W
def train(x, t, V, W, bv, bw):
	# Forward propagation -- matrix multiply + biases
	A = np.dot(x, V) + bv
	Z = np.tanh(A)

	B = np.dot(Z, W) + bw
	Y = sigmoid(B)

	# Backward propagation
	Ew = Y - t
	Ev = tanh_prime(A) * np.dot(W, Ew)

	# Predict loss
	Dw = np.outer(Z, Ew)
	Dv = np.outer(x, Ev)

	# Cross Entropy (loss function)
	loss = -np.mean(t * np.log(Y) + (1 - t) * np.log(1 - Y))

	return loss, (Dv, Dw, Ev, Ew)

# Prediction function
# x : Input Data
# V : Layer 1
# W : Layer 2
# bv: Bias V
# bw: Bias W
def predict(x, V, W, bv, bw):
	A = np.dot(x, V) + bv
	B = np.dot(np.tanh(A), W) + bw
	return (sigmoid(B) > 0.5).astype(int)

# Create layers
V = np.random.normal(scale=0.1, size=(n_input, n_hidden))
W = np.random.normal(scale=0.1, size=(n_hidden, n_output))

bv = np.zeros(n_hidden)
bw = np.zeros(n_output)

params = [V, W, bv, bw]


# Generate data
X = np.random.binomial(1, 0.5, (n_sample, n_input))
T = X ^ 1

# Train
for epoch in range(100):
	err = []
	update = [0] * len(params)
	t0 = time.clock()
	# For each data point, update weights
	for i in range(X.shape[0]):
		loss, grad = train(X[i], T[i], *params)
		#Update loss
		for j in range(len(params)):
			params[j] -= update[j]
		for j in range(len(params)):
			update[j] = learning_rate * grad[j] + momentum * update[j]

		err.append(loss)
	print("Epoch: %d, Loss: %.8f, Time: %.4fs" %(epoch, np.mean(err), time.clock() - t0))

# Testing
x = np.random.binomial(1, 0.5, n_input)
print("XOR Prediction")
print(x)
print(predict(x, *params))










