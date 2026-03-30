#program to print mean, variance, and standard deviation of a collection of numbers

import math
n = int(input("Enter number of numbers: "))
lst = []
for i in range(n):
    x = int(input("Enter number: "))
    lst.append(x)
mean = sum(lst)/x
var =0
for i in lst:
    var = var + (i-mean)**2
var = var/n
sd = math.sqrt(var)
print("Mean: ",mean)
print("Variance: ",var)
print("Standard Deviation: ",sd)
