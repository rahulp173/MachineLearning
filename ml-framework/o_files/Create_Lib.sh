gcc -c ../src/vector/*.c -I ../include -Wall
gcc -c ../src/matrix/*.c -I ../include -Wall
gcc -c ../src/operations/*.c -I ../include -Wall

ar rcs ../lib/libml-framework.a *.o