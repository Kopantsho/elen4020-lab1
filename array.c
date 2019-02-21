#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int** create2DArray(int dimension)
{
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

int*** create3DArray(int rank)
{
	int*** matrix = (int***)malloc(rank*sizeof(int**));

	for (int row = 0; row < rank; row++)
	{
		matrix[row] = (int**)malloc(rank*sizeof(int*));

		for (int column = 0; column < rank; column++)
		{
			matrix[row][column] = (int*)malloc(rank*sizeof(int));
		}
	}

	for (int row = 0; row < rank; row++)
	{
		for (int column = 0; column < rank; column++)
		{
			for (int depth = 0; depth < rank; depth++)
			{
				matrix[row][column][depth] = rand()% 21;
			}
		}
	}
	
return matrix;

}

void destroy2DArray(int** array, int size)
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

int*** rank3TensorAdd(int*** A, int*** B, int rank)
{
	int*** result = (int***)malloc(rank*sizeof(int**));

		for (int row = 0; row < rank; row++)
	{
		result[row] = (int**)malloc(rank*sizeof(int*));

		for (int column = 0; column < rank; column++)
		{
			result[row][column] = (int*)malloc(rank*sizeof(int));
		}
	}

	
	for (int depth = 0; depth < rank; depth++)
	{
		for (int row= 0; row < rank; row++)
		{
			for (int column = 0; column < rank; column++)
			{
				result[row][column][depth] = A[row][column][depth] + B[row][column][depth];
			}
		}
	}

return result;
}
 
 int*** rank3TensorMult(int*** A, int*** B, int rank)
 {
	 	int*** result = (int***)malloc(rank*sizeof(int**));

		for (int row = 0; row < rank; row++)
	{
		result[row] = (int**)malloc(rank*sizeof(int*));

		for (int column = 0; column < rank; column++)
		{
			result[row][column] = (int*)malloc(rank*sizeof(int));
		}
	}

		
	for (int depth = 0; depth < rank; depth++)
	{
		for (int column= 0; column < rank; column++)
		{
			for (int row = 0; row < rank; row++)
			{
				result[row][column][depth] = A[depth][row][column] + B[row][depth][column];
			}
		}
	}

	return result;
 }

void print3DFunc(int*** matrix, int rank)
{
	printf("This is a %d x %d x %d matrix\n", rank, rank, rank);

	for (int row = 0; row < rank; row++)
	{
		for (int column = 0; column < rank; column++)
		{
			for (int depth = 0; depth < rank; depth++)
			{
				printf("%d\t", matrix[row][column][depth]);
			}
			printf("\n");
		}
		printf("\n");
	}
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
    srand(time(NULL));
    
	int size = 3;

	// int** Array1 = create2DArray(size);
	// printFunc(Array1, size);
	
	// int** Array2 = create2DArray(size);
	// printFunc(Array2, size);
	
	// int** C1 = rank2TensorAdd(Array1, Array2, size);
	// printFunc(C1, size);
	
	// int** C2 = rank2TensorMult(Array1, Array2, size);
	// printFunc(C2, size);

	int*** Array3 = create3DArray(size);
	print3DFunc(Array3, size);
	
	int*** Array4 = create3DArray(size);
	print3DFunc(Array4, size);

	// int*** C3 = rank3TensorAdd(Array3, Array4, size);
	// print3DFunc(C3, size);

	int*** C4 = rank3TensorMult(Array3, Array4, size);
	print3DFunc(C4, size);
	
 //  destroy2DArray(Array1, size);
//    destroy2DArray(Array2, size);
//    destroy2DArray(C1, size);
//    destroy2DArray(C2, size);
	printf("hello world");
	
	return 0;
}
