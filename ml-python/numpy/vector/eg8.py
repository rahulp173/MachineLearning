import numpy
coefficient=numpy.array([2,0,4,0,10])
polynomial=numpy.poly1d(coefficient)
print(type(polynomial))
print(polynomial)
x=2
result=polynomial(x)
print(result)