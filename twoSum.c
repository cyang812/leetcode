#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int *ret = (int *)malloc(2*sizeof(int));
    int i,j;
    
    for(i = 0; i<numsSize; i++)
    {
        for(j = i+1; (j<numsSize && j!=i); j++)
        {
            if((nums[i]+nums[j])==target)
            {
                ret[0] = nums[i];
                ret[1] = nums[j];
            }
        }
    }
    return ret;
}

void main()
{
	int num[3] = {3,2,4};
	int target  = 5;
	int *res;

	res = twoSum(num,3,target);
	printf("%d,%d\n",res[0],res[1]);
}
