/*
* @Author: cyang
* @Date:   2018-08-03 17:49:42
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 18:01:56
*/

#include <stdio.h>

int findLengthOfLCIS(int* nums, int numsSize) {
	int ret = 1;
	int cnt = 1;

	if (numsSize == 0)
		return 0;

	for (int i = 0; i < numsSize - 1; ++i)
	{
		if (nums[i] < nums[i+1])
		{
			cnt++;
			if (ret < cnt)
				ret = cnt;
		}
		else
		{
			cnt = 1;
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	// int nums[] = {1,3,5,4,7};
	// int nums[] = {2,2,2,2,2,2,2,2};
	int nums[] = {1,3,5,4,2,3,4,5};
	int numsSize = sizeof(nums)/sizeof(int);

	int ret = findLengthOfLCIS(nums, numsSize);

	printf("%d\n", ret);

	return 0;
}