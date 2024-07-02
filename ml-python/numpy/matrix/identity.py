import numpy
a=numpy.matrix(((10,20),(30,40)))
print('a\n',a)
b=numpy.linalg.inv(a)
print('inverse a\n',b)
c=a*b
print('identity matrix\n',c)
c=numpy.dot(a,b)
print('identity matrix\n',c)

#This example is not working properly need to check later