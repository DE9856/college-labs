#a program to to enter marks and find total marks, percentages using classes

class student:
    def __init__(self):
        self.name = input("Enter name: ")
        self.usn = input("Enter USN: ")
        self.marks = []
    def takemarks(self):
        self.marks.append(int(input("Enter physics marks: ")))
        self.marks.append(int(input("Enter chemistry marks: ")))
        self.marks.append(int(input("Enter python marks: ")))
    def display(self):
        print("Name: ",self.name)
        print("USN: ",self.usn)
        print("Physics Marks: ",self.marks[0])
        print("Chemistry Marks: ",self.marks[1])
        print("Python Marks: ",self.marks[2])
        print("Percentage: ",sum(self.marks)/3)
s1 = student()
s1.takemarks()
s1.display()
