/*
* @Author: cyang
* @Date:   2018-08-03 11:52:14
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 12:56:03
*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int ret_cnt = 0;
	int bak = nums[0] - 1;
	printf("%d\n", bak);

	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != bak)
		{
			bak = nums[i];
			nums[ret_cnt++] = nums[i];
		}
	}

	return ret_cnt;
}

int main(int argc, char const *argv[])
{
	int nums[] = {-1,-1,0,0,1,1,1,2,2,3,3,4};
	int ret_cnt = 0;

	ret_cnt = removeDuplicates(nums, sizeof(nums)/sizeof(int));

	for (int i = 0; i < ret_cnt; ++i)
	{
		printf("%d ", nums[i]);
	}

	int i = 0xffffffff;
	printf("%d\n", i);

	return 0;
}