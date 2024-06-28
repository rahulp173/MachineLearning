import numpy
#x=numpy.matrix((10,20),(30,50))  wrong way as what we passed is not a tuple
x=numpy.matrix(((10,20),(30,50)))
print(x)
print(type(x))