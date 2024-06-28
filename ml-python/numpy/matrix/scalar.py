import numpy
a=numpy.matrix(((10,20),(30,40)))
b=a+10
print('a\n',a)
print('a+10\n',b)
b=numpy.add(a,10)
print('a+10\n',b)


b=a-10
print('a\n',a)
print('a-10\n',b)
b=numpy.subtract(a,10)
print('a-10\n',b)

b=a*10
print('a\n',a)
print('a*10\n',b)
b=numpy.dot(a,10)
print('a*10\n',b)

b=a/10
print('a\n',a)
print('a/10\n',b)
b=numpy.divide(a,10)
print('a/10\n',b)

b=a%3
print('a\n',a)
print('a mod 3\n',b)
b=numpy.mod(a,3)
print('a mod 3\n',b)