#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int** createArray(int dimension)
{

	srand(time(NULL));
	int* values = calloc(dimension*dimension, sizeof(int));
	int** rows  = malloc(dimension*sizeof(int*));
	
	
	for(int i=0; i < dimension; i++)
	{
		rows[i] = values + i*dimension;
	}
	
	for(int i=0; i<dimension; i++)
	{
		for(int j=0; j<dimension;j++)
		{
			rows[i][j] = rand() % 21; 
		}
	}
	
	return rows;
}

void destroyArray(int** array, int size)
{
	for(int i=0; i<size; i++){
	free(array[i]);
	}
	free(array);
}


int** rank2TensorAdd(int** A, int**B, int N)
{
	int* numbers = calloc(N*N, sizeof(int));
	int** result = malloc(N*sizeof(int*));
	
	for(int i=0; i<N; i++)
	{
		result[i] = numbers + i*N;
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			result[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return result;
}

int** rank2TensorMult(int** A, int** B, int N)
{
	int* numbers = calloc(N*N, sizeof(int));
	int** result = malloc(N*sizeof(int*));
	
	for(int i=0; i<N; i++)
	{
		result[i] = numbers + i*N;
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	return result;
}

void printFunc(int** matrix, int size)
{
	printf("This is an %d by %d matrix \n", size, size);
	for(int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
  		{
     		printf("%d  	", matrix[i][j]);
  		}
	printf("\n");
	}	
}

int main()
{
	int size = 5;

	int** Array1 = createArray(size);
	printFunc(Array1, size);
	
	int** Array2 = createArray(size);
	printFunc(Array2, size);
	
	int** C1 = rank2TensorAdd(Array1, Array2, size);
	printFunc(C1, size);
	
	int** C2 = rank2TensorMult(Array1, Array2, size);
	printFunc(C2, size);
	
	destroyArray(Array1, size);
	destroyArray(Array2, size);
	destroyArray(C1, size);
	destroyArray(C2, size);
	printf("hello world");
	
	return 0;
}




