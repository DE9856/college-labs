#a program to check whether the given number is an armstrong number or not

n = int(input())
length = len(str(n))
temp = n
sum = 0
while temp >0:
    x = temp%10
    sum = sum + x**length
    temp = temp//10
if sum==n:
    print("Armstrong Number")
else:
    print("Not an armstrong number")
