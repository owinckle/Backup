import ConfigParser
from subprocess import call

data = ConfigParser.ConfigParser()

def updateData():
	with open("data.ini", "w") as dataFile:
		data.write(dataFile)

def add(usr_input):
	if "name" in usr_input:
		toAdd = raw_input("\033[36mYuki> \033[32mWhat's your name?\n")
		data.set("USER", "NAME", toAdd)

	updateData()

def cmd(usr_input):
	if "ls" in usr_input:
		print("\033[36mYuki> \033[32m" + data.get("CMD", data.get("YUKI", "humor")))
		call(["ls", "-la"])

def humorUpdate(usr_input):
	pts = data.get("YUKI", "humorpts")
	if "here's" in usr_input:
		pts = str(int(pts) + 1)
	elif "no" in usr_input:
		pts = str(int(pts) - 1)
	else:
		print("\033[36mYuki> \033[32mWhat's about cookies?")

	if int(pts) > 5:
		data.set("YUKI", "humor", "happy")
	elif int(pts) < -5:
		data.set("YUKI", "humor", "unhappy")
	else:
		data.set("YUKI", "humor", "neutral")
	data.set("YUKI", "humorpts", pts)
	updateData()

def main():
	data.read("data.ini")
	while 42:
		userName = data.get("USER", "NAME")
		usr_input = raw_input("\033[36m" + userName + "> \033[32m")
		
		if "add" in usr_input:
			add(usr_input)
		
		elif usr_input in ["bye", "Bye"]:
			print("\033[36mYuki> \033[32mBye " + userName + "\n")
			exit()
		
		elif usr_input in ["Hey", "hey", "Hello", "hello"]:
			print("\033[36mYuki> \033[32m" + data.get("GREET", data.get("YUKI", "humor")))

		elif "cookie" in usr_input:
			humorUpdate(usr_input)

		elif "cmd" in usr_input:
			cmd(usr_input)

		else:
			print("\033[36mYuki> \033[32mI did not quite understand what you just said..")

if __name__ == "__main__":
	print("\033[36mYuki> \033[32mHmmm?")
	main()