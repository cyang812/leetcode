/*
* @Author: cyang
* @Date:   2018-09-29 10:24:58
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 10:41:47
*/

#include <stdio.h>

int sum(int *nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
	}
	return sum;
}

int pivotIndex(int* nums, int numsSize) {
	
	int res_idx = -1;

	for (int i = 0; i < numsSize; ++i)
	{
		if ( sum(nums, i) == sum(&nums[i+1], numsSize-i-1) )
		{
			res_idx = i;
			break;
		}

		// if(i == 2)
		// {
		// 	printf("%d\n", sum(nums, i));
		// 	printf("%d\n", sum(&nums[i+1], numsSize-i));
		// }
	}

	return res_idx;
}

int main(int argc, char const *argv[])
{
	// int nums[] = {1, 7, 3, 6, 5, 6};
	// int nums[] = {-1, -1, -1, 0, 1, 1};
	int nums[] = {-1, -1, 0, 0, -1, -1};
	// int nums[] = {1, 2, 3};
	int res = 0;

	res = pivotIndex(nums, sizeof(nums)/sizeof(nums[0]));
	printf("res = %d\n", res);

	return 0;
}