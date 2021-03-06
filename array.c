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

	if (array_error_checking_2D (rows, dimension))
	{
		EXIT_FAILURE;
	}

	else
	{
		return rows;
	}
		
}

int array_error_checking_2D (int** array, int dimension)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (array[i][j] < 0)
			{
				fprintf(stderr, "Random number less than 0");
				return 1;
			}

			if (array[i][j] > 20)
			{
				fprintf(stderr, "Random number greater than 20");
				return 1;
			}
		}
	}

	return 0;

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

	for (int depth = 0; depth < rank; depth++)
	{
		for (int row = 0; row < rank; row++)
		{
			for (int column = 0; column < rank; column++)
			{
				matrix[row][column][depth] = rand()% 21;
			}
		}
	}

	if (array_error_checking_3D(matrix, rank))
	{
		EXIT_FAILURE;
	}
	
	else
	{
		return matrix;
	}
}

int array_error_checking_3D (int*** array, int dimension)
{
	for (int k = 0; k < dimension; k++)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				if (array[i][j][k] < 0)
				{
				fprintf(stderr, "Random number less than 0");
				return 1;
				}

				if (array[i][j][k] > 20)
				{
				fprintf(stderr, "Random number greater than 20");
				return 1;
				}
			}
		}
	}
	
	return 0;

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
		for (int row= 0; row < rank; row++)
		{
			for (int column = 0; column < rank; column++)
			{
				for (int u = 0; u < rank; u++)
				{
					result[row][column][depth] += A[row][u][depth]*B[u][column][depth];
				}
			}
		}
	}

	return result;
 }

void print3DFunc(int*** matrix, int rank)
{
	printf("This is a %d x %d x %d matrix\n", rank, rank, rank);

	for (int depth = 0; depth < rank; depth++)
	{
		// printf("Layer %d", depth);
		// printf("\n");

		for (int row = 0; row < rank; row++)
		{	
			for (int column = 0; column < rank; column++)
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
    
	int size = 10;

	int** Array1 = create2DArray(size);
	printFunc(Array1, size);
	
	int** Array2 = create2DArray(size);
	printFunc(Array2, size);
	
	printf("\nN = 10 2D Matrix Addition Result\n");
	int** C1 = rank2TensorAdd(Array1, Array2, size);
	printFunc(C1, size);
	
	printf("\nN = 10 2D Matrix Multiplication Result\n");
	int** C2 = rank2TensorMult(Array1, Array2, size);
	printFunc(C2, size);

	int*** Array3 = create3DArray(size);
	print3DFunc(Array3, size);
	
	int*** Array4 = create3DArray(size);
	print3DFunc(Array4, size);

	printf("\nN = 10 3D Matrix Addition Result\n");
	int*** C3 = rank3TensorAdd(Array3, Array4, size);
	print3DFunc(C3, size);

	printf("\nN = 10 3D Matrix Multiplication Result\n");
	int*** C4 = rank3TensorMult(Array3, Array4, size);
	print3DFunc(C4, size);
	
	size = 20;

	int** Array5 = create2DArray(size);
	printFunc(Array5, size);
	
	int** Array6 = create2DArray(size);
	printFunc(Array6, size);

	printf("\nN = 20 2D Matrix Addition Result\n");
	int** C5 = rank2TensorAdd(Array5, Array6, size);
	printFunc(C5, size);
	
	printf("\nN = 20 2D Matrix Multiplication Result\n");
	int** C6 = rank2TensorMult(Array5, Array6, size);
	printFunc(C6, size);

	int*** Array7 = create3DArray(size);
	print3DFunc(Array7, size);
	
	int*** Array8 = create3DArray(size);
	print3DFunc(Array8, size);

	printf("\nN = 20 3D Matrix Addition Result\n");
	int*** C7 = rank3TensorAdd(Array7, Array8, size);
	print3DFunc(C7, size);

	printf("\nN = 20 3D Matrix Multiplication Result\n");
	int*** C8 = rank3TensorMult(Array7, Array8, size);
	print3DFunc(C8, size);

	
	
	return 0;
}
