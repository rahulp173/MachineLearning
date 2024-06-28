import numpy
a=numpy.matrix(((10,20),(30,40)))
b=a*a
print('a\n',a)
print('a^2\n',b)
b=numpy.square(a)
print('a^2\n',b)
b=numpy.power(a,2)
print('a^2\n',b)
b=numpy.power(a,3)
print('a^3\n',b)
b=numpy.dot(a,a)
print('a^2\n',b)