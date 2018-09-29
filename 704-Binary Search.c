/*
* @Author: cyang
* @Date:   2018-09-29 10:45:06
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 11:47:15
*/

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int res = -1;
    int low = 0, high = numsSize - 1, mid;

    while(low <= high)
    {
    	mid = (low+high)/2;
    	if(nums[mid] == target)
    	{
    		res = mid;
    		break;
    	}
    	else if(nums[mid] > target)
    	{
    		high = mid - 1;
    	}
    	else
    	{
    		low = mid + 1;
    	}
    }

    return res;
}

int main(int argc, char const *argv[])
{
	// int nums[] = {-1, 0, 3, 5, 9, 12};
	int nums[] = {2, 5};
	int target = 5;

	int res = 0;

	res = search(nums, sizeof(nums)/sizeof(nums[0]), target);
	printf("res = %d\n", res);

	return 0;
}