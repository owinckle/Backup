import numpy as np
import pandas as pd

def getData(dataset):
	return np.array(pd.read_csv(dataset))

def predict():
	data	= pd.read_csv("thetas.csv")
	df		= getData("data.csv")
	_max	= [max(df[:,0]), max(df[:,1])]
	theta	= data.values
	mileage	= input("\033[35m----------\n\033[36mEnter a mileage: \033[32m")
	if mileage == "stop":
		exit()
	mil		= float(mileage)
	mileage = float(mileage) / _max[0]
	price	= float(theta[0]) + (float(theta[1]) * mileage)
	price	*= _max[1]
	if mil < 0:
		print("Incorrect mileage")
		return
	elif price < 0:
		print("A car with that mileage does not even work...")
	print("\033[36mPrice for " + str(mil) + "km is: \033[32m" + str(round(price, 2)) + "\n\033[35m----------")

def main():
	while True:
		predict()

if __name__ == "__main__":
	main()
