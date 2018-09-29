/*
*496. Next Greater Element I
*/

#include <stdio.h>
#include <stdlib.h>

#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    
	int *ret = (int *)malloc(sizeof(int)*findNumsSize);
	int flag = 0;

	*returnSize = findNumsSize;

	for (int i = 0; i < findNumsSize; ++i)
	{
		/* code */
		ret[i] = -1;
		flag = 0;

		for (int j = 0; j < numsSize; ++j)
		{
			/* code */
			if (findNums[i] == nums[j])
			{
				flag = 1;
			}
			else if (flag == 1 && findNums[i] < nums[j] )
			{
				/* code */
				ret[i] = nums[j];
				// flag = 2;
				break;
			}
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a1[] = {4,1,2};
	int b1[] = {1,3,4,2};

	// int a1[] = {2,4};
	// int b1[] = {1,2,3,4};

	int *ret = NULL;
	int returnSize;

	ret = nextGreaterElement(a1,COUNTOF(a1),b1,COUNTOF(b1),&returnSize);

	for (int i = 0; i < returnSize; ++i)
	{
		/* code */
		printf("%d ", ret[i]);
	}
	printf("\n");

	if (ret != NULL)
	{
		/* code */
		printf("free\n");
		free(ret);
		ret = NULL;
	}

	return 0;
}