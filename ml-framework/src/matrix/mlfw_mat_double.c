#include<mlfw_matrix.h>
#include<mlfw_vector.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct __mlfw_mat_double
{
	double **data;
	dimension_t rows;
	dimension_t columns;
}mlfw_mat_double;

mlfw_mat_double * mlfw_mat_double_create_new(dimension_t rows, dimension_t columns)
{
	mlfw_mat_double *matrix;
	index_t r,k;
	if(rows<=0 || columns<=0) return NULL;
	matrix=(mlfw_mat_double *)malloc(sizeof(mlfw_mat_double));
	if(matrix==NULL) return NULL;
	matrix->data=(double **)malloc(sizeof(double *)*rows);
	if(matrix->data==NULL)
	{
		free(matrix);
		return NULL;
	}
	for(r=0;r<rows;r++)
	{
		matrix->data[r]=(double *)malloc(sizeof(double)*columns);
		if(matrix->data[r]==NULL)
		{
			for(k=0; k<r; ++k)
			{
				free(matrix->data[k]);
			}
			free(matrix->data);
			free(matrix);
			return NULL;
		}
	}
	matrix->rows=rows;
	matrix->columns=columns;
	return matrix;
}
void mlfw_mat_double_destroy(mlfw_mat_double *matrix)
{
	index_t r;
	if(matrix==NULL) return;
	for(r=0;r<matrix->rows;++r)
	{
		free(matrix->data[r]);
	}
	free(matrix->data);
	free(matrix);
}
mlfw_mat_double * mlfw_mat_double_from_csv(const char *csv_file_name)
{
	mlfw_mat_double *matrix;
	char m;
	int index;
	index_t r,c;
	double value;
	char double_string[1025]; // 1 extra for \0 (string terminator)
	dimension_t rows,columns;
	FILE *file;
	if(csv_file_name==NULL) return NULL;
	file=fopen(csv_file_name, "r");
	if(file==NULL) return NULL;
	rows=0;
	columns=0;
	while(1)
	{
		m=fgetc(file);
		if(feof(file)) break;

		if(rows==0)
		{
			if(m==',') columns++;
		}

		if(m=='\n') rows++;
	}
	columns++;
	matrix=mlfw_mat_double_create_new(rows,columns);
	
	if(matrix==NULL)
	{
		fclose(file);
		return NULL;
	}

	rewind(file); //move the internal pointer to first byte
	//logic to populate matrix starts
	r=0;
	c=0;
	index=0;

	while(1)
	{
		m=fgetc(file);
		if(feof(file)) break;
		if(m==',' || m=='\n')
		{
			double_string[index]='\0';
			value=strtod(double_string,NULL);
			index=0;
			matrix->data[r][c]=value;
			c++;
			if(c==matrix->columns)
			{
				r++;
				c=0;
			}
		}
		else
		{
			double_string[index]=m;
			index++;
		}
	
	}
	fclose(file);

return matrix;
}

double mlfw_mat_double_get(mlfw_mat_double *matrix,index_t row,index_t column)
{
double value=0.0;
if(matrix==NULL) return value;
if(row<0 || row>=matrix->rows) return value;
if(column<0 || column>=matrix->columns) return value;
return matrix->data[row][column];

}
void mlfw_mat_double_set(mlfw_mat_double *matrix,index_t row,index_t column, double value)
{
if(matrix==NULL) return;
if(row<0 || row>=matrix->rows) return;
if(column<0 || column>=matrix->columns) return;
matrix->data[row][column]=value;
}


void mlfw_mat_double_get_dimensions(mlfw_mat_double *matrix,dimension_t *rows,dimension_t *columns)
{
	if(matrix==NULL) return;
	if(rows!=NULL)
	{
		*rows=matrix->rows;
	}
	if(columns!=NULL)
	{
		*columns=matrix->columns;
	}
}

void mlfw_mat_double_copy(mlfw_mat_double *target,mlfw_mat_double *source,index_t target_row_index,index_t target_column_index,index_t source_from_row_index,index_t source_from_column_index,index_t source_to_row_index,index_t source_to_column_index)
{
	index_t target_r;
	index_t target_c;

	index_t source_r;
	index_t source_c;

	if(target==NULL || source==NULL) return;

	if(target_row_index<0 || target_row_index>=target->rows) return;
	if(target_column_index<0 || target_column_index>=target->columns) return;

	if(source_from_row_index<0 || source_from_row_index>=source->rows) return;
	if(source_from_column_index<0 || source_from_column_index>=source->columns) return;

	if(source_to_row_index<0 || source_to_row_index>=source->rows) return;
	if(source_to_column_index<0 || source_to_column_index>=source->columns) return;

	if(source_from_row_index>source_to_row_index) return;
	if(source_from_column_index>source_to_column_index) return;

	target_r=target_row_index;
	source_r=source_from_row_index;
	while(source_r<=source_to_row_index)
	{
		target_c=target_column_index;
		source_c=source_from_column_index;
		while(source_c<=source_to_column_index)
		{
			if(target_r>=0 && target_r<target->rows && target_c>=0 && target_c<target->columns)
			{
				target->data[target_r][target_c]=source->data[source_r][source_c]
			}
			++source_c;
			++target_c;
		}
		++source_r;
		++target_r;
	}
	
}
void mlfw_mat_double_fill(mlfw_mat_double *matrix,index_t from_row_index,index_t from_column_index,index_t to_row_index,index_t to_column_index,double value)
{
	index_t r,c;
	if(matrix==NULL) return;
	if(from_row_index>=matrix->rows) return;
	if(from_column_index>=matrix->columns) return;
	if(from_row_index<0) from_row_index=0;
	if(from_column_index<0) from_column_index=0;
	if(to_row_index>=matrix->rows) to_row_index=matrix->rows-1;
	if(to_column_index>=matrix->columns) to_column_index=matrix->columns-1;
	if(from_row_index>to_row_index) return;
	if(from_column_index>to_column_index) return;

	for(r=from_row_index;r<=to_row_index;++r)
	{
		for(c=from_column_index;c<=to_column_index;++c)
		{
			matrix->data[r][c]=value;
		}
	}
}
mlfw_column_vec_double * mlfw_mat_double_create_column_vec(mlfw_mat_double *matrix,index_t column_index)
{
	mlfw_column_vec_double *vector;
	index_t r;
	if(matrix==NULL) return NULL;
	if(column_index<0 || column_index>=matrix->columns) return NULL;
	vector=mlfw_column_vec_double_create_new(matrix->rows);
	if(vector==NULL) return NULL;
	for(r=0;r<matrix->rows;++r)
	{
		mlfw_column_vec_double_set(vector,r,matrix->data[r][column_index]);
	}
	return vector;
}