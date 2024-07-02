import numpy
a=numpy.matrix(((10,20,30,40),(50,60,70,80),(90,100,110,120)))
numpy.save('amat',a)

#above we are seeing the example of how to save matrix data into file that too in binary mode (Encoded in Binary)
#isse jo file banegi wo binary mode ki file hogi jiska extension npy hoga

#FILE *f;
#f=fopen("somefile","wb") // binary mode (sequence of bytes)