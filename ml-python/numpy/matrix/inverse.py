import numpy
a=numpy.matrix(((10,20),(30,40)))
print('a\n',a)
b=numpy.linalg.inv(a)
print('inverse a\n',b)