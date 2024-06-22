import numpy
coefficient=[2,3,4,5,10]
#coefficient=numpy.array([2,3,4,5,10]) -- can be written like this as well
polynomial=numpy.poly1d(coefficient)
print(type(polynomial))
print(polynomial)
x=2
result=polynomial(x)
print(result)