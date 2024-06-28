import numpy
a=numpy.matrix(((10,20,30),(5,4,2),(1,5,10)))
b=numpy.matrix(((2,4,6),(1,2,3),(7,6,5)))
print('a\n',a)
print('b\n',b)
c=a*b
print('a*b\n',c)
c=numpy.dot(a,b)
print('a*b\n',c)