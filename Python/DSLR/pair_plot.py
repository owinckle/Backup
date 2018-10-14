import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sb
import sys

Colors = ["#4741f4", "#12aa17", "#af0e0e", "#d7f210"]
FILE = "data/dataset_train.csv"

def pair_plot(f):
	data = pd.read_csv(f)
	data = data.drop("Index", axis=1)
	data = data.dropna()
	sb.pairplot(data, hue="Hogwarts House", palette=Colors)
	plt.show()

def main():
	f = FILE if len(sys.argv) != 2 else sys.argv[1]
	pair_plot(f)

if __name__ == '__main__':
	main()
