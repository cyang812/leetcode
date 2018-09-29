#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int *ret = (int *)malloc(2*sizeof(int));
    int i,j;
    
    for(i = 0; i<numsSize; i++)
    {
        for(j = i+1; j<numsSize; j++)
        {
            if( (nums[i]+nums[j]) == target )
            {
                ret[0] = i;
                ret[1] = j;
            }
        }
    }
    return ret;
}

int main()
{
	int num[3] = {3,2,4};
	int target  = 6;
	int *res;

	res = twoSum(num,3,target);
	printf("%d,%d\n",res[0],res[1]);
}
