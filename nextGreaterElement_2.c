/*
*503. Next Greater Element II
*/

#include <stdio.h>
#include <stdlib.h>

#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {

	int *ret = (int *)malloc(sizeof(int)*numsSize);
	int flag = 0;

	*returnSize = numsSize;

	for (int i = 0; i < numsSize; ++i)
	{
		/* code */
		ret[i] = -1;
		flag = 0;

		for (int j = i+1; j < i+numsSize; ++j)
		{
			if(nums[j%numsSize] > nums[i])
			{
				ret[i] = nums[j%numsSize];
				break;
			}
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	int a1[] = {1,2,1};

	int *ret = NULL;
	int returnSize;

	ret = nextGreaterElements(a1,COUNTOF(a1),&returnSize);

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