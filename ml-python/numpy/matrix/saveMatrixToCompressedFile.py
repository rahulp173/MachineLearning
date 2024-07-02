import numpy
a=numpy.matrix(((10,20,30),(40,50,60)))
numpy.savez_compressed('data',mat=a)

#File will be saved in compressed mode. what it means is file is going to be saved in binary mode only
#with applied algorithms on it for compression. basically it will be an array of array with compression algorithm
#to get that data we have decided one term which is mat in above case that will be required while retrieving the data