#include<mlfw_matrix.h>
#include<mlfw_vector.h>
#include<mlfw_operations.h>
#include<stdlib.h>
#include<stdio.h>

// global variable
uint64_t NUMBER_OF_ITERATIONS=3000000;


void train_it()
{
uint64_t k;
mlfw_mat_double *dataset;
dimension_t dataset_rows;
dimension_t dataset_columns;

mlfw_mat_double *I;
dimension_t I_rows;
dimension_t I_columns;

mlfw_column_vec_double *A; 
mlfw_column_vec_double *m;
mlfw_column_vec_double *P;
mlfw_column_vec_double *E;

mlfw_row_vec_double *ET;

mlfw_column_vec_double *ETE;

mlfw_mat_double *IT; // added after calculus

mlfw_column_vec_double *ITE; // (IT * E)added after calculus

mlfw_column_vec_double *TMP; // (1/n * ITE) added after calculus

mlfw_column_vec_double *UM; // (m-TMP)added after calculus

double sum_of_squared_error_values;
double final_error_value;

dataset=mlfw_mat_double_from_csv("IceCreamSales.csv");
if(dataset==NULL)
{
	printf("Unable to load dataset from IceCreamSales.csv");
	return;
}
mlfw_mat_double_get_dimensions(dataset,&dataset_rows,&dataset_columns);

I_rows=dataset_rows;
I_columns=dataset_columns-1+1; // no need to do -1+1, this just for understanding
I=mlfw_mat_double_create_new(I_rows,I_columns);
if(I==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	return;
}
// copy a=b where a is target and b is source

/*
1st arg : target matrix
2nd arg : source matric
3rd arg : target_row_index
4th arg : target_column_index
5th arg : source_from_row_index
6th arg : source_from_column_index
7th arg : source_to_row_index
8th arg : source_to_column_index
*/
mlfw_mat_double_copy(I,dataset,0,1,0,0,dataset_rows-1,0);

/*
1st arg : matrix to fill
2nd arg : from row index
3rd arg : from column index
4th arg : upto row index
5th arg : updo column index
6th arg : what to fill

*/
mlfw_mat_double_fill(I,0,0,dataset_rows-1,0,1.0);


IT=mlfw_mat_double_transpose(I);
if(IT==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	return;
}

/*
1st arg : source matrix
2nd arg : which column to use to create column vector
*/
A=mlfw_mat_double_create_column_vec(dataset,1);
if(A==NULL)
{
	printf("Unable to create column vector\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	return;
}

// We discussed that c will be 0 and m will be 1
// We also discussed that value of m and c can be anything
// hence I am taking c as 0 and m also as 0
m=mlfw_column_vec_double_create_new_filled(I_columns,0.0);
if(m==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	return;
}

// Operations start

k=1;
while(k<=NUMBER_OF_ITERATIONS)
{

P=mlfw_multiply_double_matrix_with_column_vector(I,m);
if(P==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	return;
}

/*
x=y-z
1st arg : left operand
2nd arg : right operand
*/

E=mlfw_subtract_double_column_vector(P,A);

if(E==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_column_vec_double_destroy(A);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	return;
}

ET=mlfw_column_vec_double_transpose(E);
if(ET==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	mlfw_column_vec_double_destroy(E);
	return;
}

ETE=mlfw_multiply_double_row_vector_with_column_vector(ET,E);
if(ETE==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	mlfw_column_vec_double_destroy(E);
	mlfw_row_vec_double_destroy(ET);
	return;
}

sum_of_squared_error_values=mlfw_column_vec_double_get(ETE,0);

//final_error_value=sum_of_squared_error_values/I_rows; this has been changed by below formula as we used 1/2n in our calculus 

final_error_value=sum_of_squared_error_values/(2*I_rows);

//printf("Sum of squared error values : %41.15lf\n", sum_of_squared_error_values);
//printf("Final error value : %41.15lf\n", final_error_value);

printf("Iteration Number %" PRIu64 ", Error : %41.15lf\n", k,final_error_value);

//logic to update m and c, technically our m column vector

ITE=mlfw_multiply_double_matrix_with_column_vector(IT,E);
if(ITE==NULL)
{	
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	mlfw_column_vec_double_destroy(E);
	mlfw_row_vec_double_destroy(ET);
	return;
}

TMP=mlfw_multiply_double_scalar_with_column_vector((0.0001*(1.0/I_rows)),ITE);
if(TMP==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	mlfw_column_vec_double_destroy(E);
	mlfw_row_vec_double_destroy(ET);
	mlfw_column_vec_double_destroy(ITE);
	return;
}

UM=mlfw_subtract_double_column_vector(m,TMP);
if(UM==NULL)
{
	printf("Low memory\n");
	mlfw_mat_double_destroy(dataset);
	mlfw_mat_double_destroy(I);
	mlfw_mat_double_destroy(IT);
	mlfw_column_vec_double_destroy(A);
	mlfw_column_vec_double_destroy(m);
	mlfw_column_vec_double_destroy(P);
	mlfw_column_vec_double_destroy(E);
	mlfw_row_vec_double_destroy(ET);
	mlfw_column_vec_double_destroy(ITE);
	mlfw_column_vec_double_destroy(TMP);
	return;
}

mlfw_column_vec_double_destroy(m); // Old m vector released
m=UM; //now m is pointing to newly created vector with updated values

mlfw_column_vec_double_destroy(P);
mlfw_column_vec_double_destroy(E);
mlfw_row_vec_double_destroy(ET);
mlfw_column_vec_double_destroy(ETE);
mlfw_column_vec_double_destroy(ITE);
mlfw_column_vec_double_destroy(TMP);
++k;
}

// code to store the contents of (m vector) to csv file

//relese resources
mlfw_mat_double_destroy(dataset);
mlfw_mat_double_destroy(I);
mlfw_mat_double_destroy(IT);
mlfw_column_vec_double_destroy(A);
mlfw_column_vec_double_destroy(m); // the last m which was actually UM
}

int main()
{
train_it();
return 0;
}