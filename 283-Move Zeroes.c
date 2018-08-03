/*
* @Author: cyang
* @Date:   2018-08-03 13:48:04
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-03 13:51:57
*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    
	int idx = 0;

    for (int i = 0; i < numsSize; ++i)
    {
    	if (nums[i] != 0)
    	{
    		nums[idx++] = nums[i];
    	}
    }

    for (int i = idx; i < numsSize; ++i)
    {
    	nums[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
	int nums[] = {-1,-1,0,0,1,1,1,2,2,3,3,4};
	int numsSize = sizeof(nums)/sizeof(int);

	moveZeroes(nums, numsSize);
	for (int i = 0; i < numsSize; ++i)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}