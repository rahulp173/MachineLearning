# MachineLearning

# Create o_files
	go into O_files folder then hit below command 
		gcc -c ..\src\vector\mlfw_vec_double.c -I ..\include -Wall
		gcc -c ..\src\matrix\mlfw_mat_double.c -I ..\include -Wall
		gcc -c ..\src\operations\mlfw_operations_double.c -I ..\include -Wall
# Create library
	go into o_files folder then hit below command 
		ar rcs ..\lib\libml-framework.a *.o
			
	alternative shell command to execute into -o_files folder 
		sh .\Create_Lib.sh
			
# Compile testcase train_it.c
	go into testcases folder then hit command 
		gcc train_it.c -I ..\include -L..\lib -l ml-framework -o train_it.out 