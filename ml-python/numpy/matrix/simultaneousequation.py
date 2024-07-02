import numpy
a=numpy.matrix(((2,5),(3,10)))
b=numpy.matrix(((20,),(35,)))
c=numpy.linalg.inv(a)
print('a\n',a)
print('b\n',b)
print('inv of a\n',c)
d=c*b
print('d\n',d)