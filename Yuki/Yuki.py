import ConfigParser
# from difflib import get_close_matches

data = ConfigParser.ConfigParser()
YukiOut = "Yuki> "

def updateData():
	with open("data.ini", "w") as dataFile:
		data.write(dataFile)

def analyse(usrInput, answer):
	print(YukiOut + answer)
	if usrInput == "bye":
		exit()

def yuki():
	username = data.get("USER", "Name") + "> "
	while "yuki":
		usrInput = raw_input(username)
		try:
			answer = data.get("INPUT", usrInput)
			if answer == "":
				continue
			else:
				analyse(usrInput, answer)
		except ConfigParser.NoOptionError:
			print(YukiOut + "What should I answer?")
			usrOptionErr = raw_input(username)
			data.set("INPUT", usrInput, usrOptionErr)
		except ConfigParser.NoSectionError:
			data.add_section("INPUT")
		updateData()

def main():
	data.read("data.ini")
	if not "USER" in data.sections():
		print("Yuki> What's your name?")
		username = raw_input("Guest> ")
		data.add_section("USER")
		data.set("USER", "Name", username)
		updateData()
	yuki()

if __name__ == "__main__":
	main()