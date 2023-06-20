#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			B[j][i] = A[i][j];
		}
}

void print_matrix(int matrix[ROWS][COLS])
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void mul_matrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j <COLS; j++)
			for (int k = 0; k < ROWS; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
}

int main()
{
	int A[ROWS][COLS] = { {0,1,2}, {3,4,5}, {6,7,8} };
	int B[ROWS][COLS] = {};
	int C[ROWS][COLS] = {};

	matrix_transpose(A, B);
	print_matrix(A);
	print_matrix(B);
	print_matrix(C);

	mul_matrix(A, B, C);

	printf("\n");

	print_matrix(C);
	

	return 0;
}