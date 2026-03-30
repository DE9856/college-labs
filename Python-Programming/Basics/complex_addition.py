#a program to find addition of two complex numbers using classes and objects

class complex:
  def __init__(self,real,img):
    self.real = real
    self.img = img
  def __add__(C1,C2):
    return complex(C1.real+C2.real,C1.img+C2.img)
n = int(input("Enter number of numbers to add: "))
res = complex(0,0)
for i in range(n):
  a,b = map(int,input("Enter real and imaginary parts: ").split())
  number = complex(a,b)
  res = res + number
print("The answer is: %d + i%d"%(res.real,res.img))
