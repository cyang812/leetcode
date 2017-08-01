/*
*35. Search Insert Position
*/
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int i;

    for(i=0; i<numsSize; i++)
    {
        if(target == nums[i])
        {
            return i;
        }
    }

    for(i=0; i<numsSize; i++)
    {
        if(target < nums[0])
            return 0;

        if(target>nums[i] && target<nums[i+1])
        {
            return i+1;
        }

        if(i == numsSize-1)
        {
            return i+1;
        }
    }

    return 100;
}

int main()
{
    int a[] = {1,3,6,8,9};
    int b[] = {1};
    int size = sizeof(b)/sizeof(int);
    int target = 2;
    int ret;

    printf("size = %d\n",size);

    ret = searchInsert(b,size,target);
    printf("ret = %d\n",ret);
}
