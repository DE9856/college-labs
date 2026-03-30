#Reads a file and prints the top 10 frequently appearing words in textfile along with their frequency

fp = open("filepath","r+")
wordlist = []
dst = {}
for lines in fp.readlines():
    wordlist += lines.split()
for wd in wordlist:
    dst[wd] = wordlist.count(wd)
sortedlist = sorted(dst,key = dst.get,reverse = True)
count = 0
for i in sortedlist:
    print(count+1," Frequency of Word \"",i,":",dst[i])
    count = count+1
    if count ==10:
        break
