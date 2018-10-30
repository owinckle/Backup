# coding=utf-8
import urllib
from sys import argv
import re

ignore = ["Demande à ton voisin de gauche  \n",
        "Non ce n'est toujours pas bon ...\n",
        "Demande à ton voisin du dessous \n",
        "Demande à ton voisin du dessus  \n",
        "Toujours pas tu vas craquer non ?\n",
        "Demande à ton voisin de droite  \n",
        "Tu veux de l'aide ? Moi aussi !  \n"]

def crawl(ip):
    f = urllib.urlopen(ip)
    html = f.read()
    links = re.findall('<a href="(.*?)">', html, re.MULTILINE)
    del links[0]
    for link in links:
        if link == "README":
            readData = urllib.urlopen(ip + "README").read()
            if readData not in ignore:
                print(readData)
                exit()
            break
        crawl(ip + link)

def main(ip):
    url = "http://" + ip + "/.hidden/"
    crawl(url)

if __name__ == "__main__":
    try:
        ip = argv[1]
        main(ip)
    except IndexError:
        print("Error: No ip (ex: python crawler.py 192.168.255.129)")