/*
* @Author: cyang
* @Date:   2018-08-03 11:27:59
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 11:47:28
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int idx = 0;

	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != val)
		{
			nums[idx++] = nums[i];
		}
	}

	return idx;
}


int main(int argc, char const *argv[])
{
	int nums[] = {0,1,2,2,3,0,4,2};
	// int nums[] = {3,2,2,3};
	int key = 2;
	int ret_cnt = 0;

	ret_cnt = removeElement(nums, sizeof(nums)/sizeof(int), key);

	for (int i = 0; i < ret_cnt; ++i)
	{
		printf("%d ", nums[i]);
	}   


	return 0;
}
