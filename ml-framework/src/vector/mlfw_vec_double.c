#include<stdio.h>
#include<stdlib.h>
#include<mlfw_vector.h>

typedef struct __mlfw_column_vec_double
{
}mlfw_column_vec_double;
typedef struct __mlfw_row_vec_double
{
}mlfw_row_vec_double;

// column vector function prototypes
mlfw_column_vec_double * mlfw_column_vec_double_create_new(dimension_t size)
{
	return NULL;
}
void mlfw_column_vec_double_destroy(mlfw_column_vec_double *vector)
{
}
double mlfw_column_vec_double_get(mlfw_column_vec_double *vector,index_t index)
{
	return 0.0;
}
void mlfw_column_vec_double_set(mlfw_column_vec_double *vector,index_t index,double value)
{
}
mlfw_column_vec_double * mlfw_column_vec_create_new_filled(dimension_t size, double value)
{
	return NULL;
}
mlfw_row_vec_double * mlfw_column_vec_double_transpose(mlfw_column_vec_double *vector)
{
	return NULL;
}
dimension_t mlfw_column_vec_double_get_size(mlfw_column_vec_double *vector)
{
	return 0;
}

// row vector function prototypes
mlfw_row_vec_double * mlfw_row_vec_double_create_new(dimension_t size)
{
	return NULL;
}
void mlfw_row_vec_double_destroy(mlfw_row_vec_double *vector)
{
}
double mlfw_row_vec_double_get(mlfw_row_vec_double *vector,index_t index)
{
	return 0.0;
}
void mlfw_row_vec_double_set(mlfw_row_vec_double *vector,index_t index,double value)
{
}
mlfw_row_vec_double * mlfw_row_vec_create_new_filled(dimension_t size,double value)
{
	return NULL;
}
mlfw_column_vec_double * mlfw_row_vec_double_transpose(mlfw_row_vec_double *vector)
{
	return NULL;
}
dimension_t mlfw_row_vec_double_get_size(mlfw_row_vec_double *vector)
{
	return 0;
}
