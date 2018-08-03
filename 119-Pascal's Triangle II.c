/*
* @Author: cyang
* @Date:   2018-08-03 16:04:51
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 17:43:21
*/

/*
 * -- 比 ++ 好用的地方
 * 数据的计算方向相反，从而带来的便利
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
	
	*returnSize = rowIndex + 1;	
	int *retArray = (int *)malloc(sizeof(int) * (*returnSize));

	for (int i = 0; i < *returnSize; ++i)
	{
		retArray[i] = 1;
		for (int j = i-1; j > 0; j--)  // --表示数据从右向左计算，此时相应位不会被覆盖
		{
			retArray[j] = retArray[j-1] + retArray[j];			
		}
	}

	return retArray;
}

int main(int argc, char const *argv[])
{
	int rowIndex = 6;
	int returnSize = 0;
	int *retArray = NULL;

	retArray = getRow(rowIndex, &returnSize);

	for (int i = 0; i < returnSize; ++i)
	{
		printf("%d ", retArray[i]);
	}

	return 0;
}