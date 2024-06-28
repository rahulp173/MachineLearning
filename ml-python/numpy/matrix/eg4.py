import numpy
a=numpy.matrix(((10,20),(30,50)))
b=numpy.matrix(((1,2,5),(3,4,7)))
print(f"Shape of (a) matrix is {a.shape}")
print('a\n',a)
print(f"Shape of (b) matrix is {b.shape}")
print('b\n',b)
c=numpy.add(a,b)  # wrong as shape are not same
print('c\n',c)