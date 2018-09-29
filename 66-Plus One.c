/*
*66. Plus One
*/

#include <stdio.h>
#include <stdlib.h>

#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
	int ret_array_size = digitsSize+1;
	int *ret_array = (int *)malloc(sizeof(int)*ret_array_size);
	int inc = 1;
	int flag = 0;
	printf("digitsSize = %d\n", digitsSize);

	while(digitsSize)
	{
		if (inc)
		{
			if (digits[digitsSize-1] == 9)
			{
				/* code */
				ret_array[digitsSize] = 0;
			}
			else if (digits[digitsSize-1] != 9)
			{
				ret_array[digitsSize] = digits[digitsSize-1]+1;
				inc = 0;
			}
		}
		else
		{
			ret_array[digitsSize] = digits[digitsSize-1];
		}
		digitsSize--;
	}

	if (inc)
	{
		ret_array[0] = 1;
		*returnSize = ret_array_size;
	}
	else
	{
		ret_array = (int *)&ret_array[1];
		*returnSize = ret_array_size-1;
	}

	printf("inc = %d\n", inc);
	return ret_array;
}

int main(int argc, char const *argv[])
{
	/* code */
	// int array[3] = {1,3,9};
	int array[] = {9,8,7,6,5,4,3,2,1,0};

	int *retVal = NULL;
	int returnSize = 0;

	retVal = plusOne(array,COUNTOF(array),&returnSize);

	printf("returnSize = %d\n",returnSize);
	for (int i = 0; i < returnSize; ++i)
	{
		/* code */
		printf("%d ", retVal[i]);
	}

	if (retVal)
	{
		/* code */
		printf("\nfree\n");
		free(retVal);
		retVal = NULL;
	}

	return 0;
}