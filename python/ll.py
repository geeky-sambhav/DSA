class Rectangle:
 def __init__(self,length,breath):
    self.length=length
    self.breath=breath

 def area(self):
    area= self.length*self.breath
    return area

 def __lt__(self,other):
    if (self.area()<other.area()):
        print("area is smaller")
    else:
        print("area is larger")
 def __add__(self,other):
    return self.breath+other.breath
op1=Rectangle(1,4)
op2=Rectangle(3,2)
print(op1+op2)