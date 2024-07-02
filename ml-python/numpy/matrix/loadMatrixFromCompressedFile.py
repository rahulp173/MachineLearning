import numpy
a=numpy.load('data.npz')
print(a)
b=a["mat"]
print(b)

#File will be saved in compressed mode. what it means is file is going to be saved in binary mode only
#with applied algorithms on it for compression. basically it will be an array of array with compression algorithm
#to get that data we have decided one term which is mat in above case that will be required while retrieving the data