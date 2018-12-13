import sys

import pandas as pd
import numpy as np

from net import Network, SIGMOID, SOFTMAX

def main(dataset):
	expect	= np.transpose(np.array(pd.read_csv(dataset)))[0]
	inputs	= np.transpose(np.array(pd.read_csv(dataset).drop("class", axis=1)))
	''' Generate Biases '''
	# inputs	= np.vstack([inputs, np.ones(len(expect))])
	for x in inputs:
		print(x)
	network = Network([2, 2, 1], SIGMOID, SOFTMAX)

if __name__ == "__main__":
	if len(sys.argv) == 2:
		main(sys.argv[1])
	else:
		print("No dataset")