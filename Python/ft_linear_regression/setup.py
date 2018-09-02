data_file = "data"
data = "0,0"

def setData():
	file = open(data_file, "w")
	file.writelines(data)
	file.close()
	print("\033[35mDone.")
	exit()

def main():
	setData()

if __name__ == '__main__':
	main()
