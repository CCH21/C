#include <stdio.h>

int main(void)
{
	int matrix1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int matrix2[3][3] = {
		{9, 8, 7},
		{6, 5, 4},
		{3, 2, 1}
	};
	int newMatrix[3][3] = {0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
			printf("%3d", newMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
