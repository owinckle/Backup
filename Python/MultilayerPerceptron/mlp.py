import sys

import pandas as pd
import numpy as np

from net import Network, SIGMOID, SOFTMAX

def main(dataset):
	inputs	= np.array(pd.read_csv(dataset))
	network = Network([2, 2, 1], SIGMOID, SIGMOID)
	network.train(inputs, iteration=1)

if __name__ == "__main__":
	if len(sys.argv) == 2:
		main(sys.argv[1])
	else:
		print("No dataset")