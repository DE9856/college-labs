#A program to check whether the given input year is a leap year or not

n = int(input("Enter year"))
if n%400==0:
    print("Leap year")
elif n%4==0 and n%100!=0:
    print("Leap year")
else:
    print("Not a leap year")
