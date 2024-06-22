import numpy
a=numpy.array([10,20,30])
b=numpy.array([5,6,7])
c=numpy.dot(a,b)
print('a.b',c)
#10*5 + 20*6 + 30*7
#50 + 120 +210
#380
d = a @ b # This is present for ndarray
print('d',d)