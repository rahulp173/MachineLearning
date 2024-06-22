import numpy
a=numpy.array([10,5,20])
b=numpy.array([5,2,100])
c=numpy.cross(a,b)
print('axb',c)
#(5*100-20*2) - (10*100-20*5)  - (10*2-5*5)