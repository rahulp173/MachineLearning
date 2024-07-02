import numpy
#create csv file , comma separated values
a=numpy.matrix(((10,20,30),(40,50,60)))
numpy.savetxt('whatever',a,delimiter=',')