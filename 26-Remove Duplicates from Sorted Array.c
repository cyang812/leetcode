/*
* @Author: cyang
* @Date:   2018-08-03 11:52:14
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 12:01:45
*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int ret_cnt = 0;
	int bak;

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
	int nums[] = {0,0,1,1,1,2,2,3,3,4};
	int ret_cnt = 0;

	ret_cnt = removeDuplicates(nums, sizeof(nums)/sizeof(int));

	for (int i = 0; i < ret_cnt; ++i)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}