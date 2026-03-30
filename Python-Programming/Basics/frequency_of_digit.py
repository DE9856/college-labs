#takes an input of a number, and finds frequency of each digit present inside the number

n = input("Enter number")
for i in set(n):
    count = 0
    for j in n:
        if i==j:
            count = count+1
    print(i,":",count)
