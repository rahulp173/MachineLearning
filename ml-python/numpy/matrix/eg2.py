import numpy
a=numpy.matrix(((10,20),(30,50)))
b=numpy.matrix(((1,2),(3,4)))
print('a\n',a)
print('b\n',b)

c=a+b    # when we use + with two objects a and b it calls magic method which basically call __add__ method shown below
print('c\n',c)

c=a.__add__(b)
print('c\n',c)
