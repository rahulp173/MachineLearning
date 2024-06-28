import numpy
a=numpy.matrix(((10,20),(30,50)))
b=numpy.matrix(((1,2),(3,4)))
print('a\n',a)
print('b\n',b)
c=a-b;
print('a-b\n',c)
c=numpy.subtract(a,b)
print('a-b\n',c)