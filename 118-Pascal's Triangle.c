/*
* @Author: cyang
* @Date:   2018-08-03 13:56:04
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 16:00:23
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * [out] int** returnArray : 一个包含 numRows 个 int 型指针的数组
 * [out] columnSizes : 一个一维数组，记录每一行的元素个数
 */
int** generate(int numRows, int** columnSizes) {

    int** returnArray = (int**)malloc(sizeof(int*)*numRows); //分配一个包含指针变量的数组
    *columnSizes = (int*)malloc(sizeof(int)*numRows);

    for(int i=0; i < numRows; i++)
    {
        (*columnSizes)[i] = i+1;
        returnArray[i] = (int*)malloc(sizeof(int)*(i+1));
        returnArray[i][0] = 1;
        returnArray[i][i] = 1;
        for(int j=1; j<i; j++)
        {
            returnArray[i][j] = returnArray[i-1][j] + returnArray[i-1][j-1];
        }
    }

    return returnArray;
}

void twoDimensionalArray()
{
	// a: int *[3];
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int cnt = sizeof(a)/sizeof(int);

	// -1
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//printf("%d ", a[i][j]);
			printf("%d ", *(*(a+i)+j));
		}
	}

	// -2
	int *b = (int *)a;
	for (int i = 0; i < cnt; ++i)
	{
		/* code */
		int temp = b[i];
		printf("%d ", temp);
	}
}

int main(int argc, char const *argv[])
{
	twoDimensionalArray();
	return 0;

	int numRows = 15;
	int **arrays = NULL;
	int *columnSizes = NULL;

	arrays = generate(numRows, &columnSizes);

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < columnSizes[i]; ++j)
		{
			/* code */
			// printf("%d ", arrays[i][j]);
			//printf("%d ", *(arrays[i]+j)); // 等价于
			printf("%d ", *(*(arrays+i)+j)); // 等价于
		}
		printf("\n");
	}

	if (arrays)
	{
		for (int i = 0; i < numRows; ++i)
		{
			if(arrays[i])
			{
				free(arrays[i]);
			}
		}

		free(arrays);
	}

	if (columnSizes)
	{
		free(columnSizes);
	}
	
	return 0;
}
