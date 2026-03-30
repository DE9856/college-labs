#a program to read the contents of a text file, and write the sorted contents into another text file

fp = open("filepath to read from","r+")
wordlist = []
for line in fp.readlines():
    wordlist += line.split()
wordlist.sort()
str1 = " ".join(wordlist)
fp1 = open("filepath to write in","w+")
fp1.write(str1)
fp.close()
fp1.close()
