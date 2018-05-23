def main():
	try:
		file = open("data", "r")
	except IOError:
		print("Error reading data from data")
		exit(1)
	data = list(file)
	theta = data[0].split(",")
	mileage = input("\033[35m----------\n\033[36mEnter a mileage: \033[32m")
	price = float(theta[0]) + (float(theta[1]) * float(mileage))
	print("\033[36mPrice for " + str(mileage) + "km is: \033[32m" + str(round(price, 2)) + "\n\033[35m----------")

if __name__ == "__main__":
	main()