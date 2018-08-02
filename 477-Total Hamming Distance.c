/*
* @Author: cyang
* @Date:   2018-08-02 14:42:08
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-02 15:39:38
*/

#include <stdio.h>
#include <stdint.h>

int hammingDistance(int x, int y) {
	int ret = 0;

	#if 0
	for (int i = 0; i < 32; ++i)
	{
		/* code */
		int a = x & 0x01;
		int b = y & 0x01;

		if(a != b)
			ret++;

		x >>= 1;
		y >>= 1;
	}
	#else
	int temp = x ^ y;

	for (int i = 0; i < 32; ++i)
 	{
 		if(temp & 0x01)
 			ret++;

 		temp = temp >> 1;
 	} 
	#endif

	return ret;
}

#if 0 //time limit
int totalHammingDistance(int* nums, int numsSize) {
 
	int ret = 0;
	int count = 0;

    for (int i = 0; i < numsSize-1; ++i)
    {
    	for (int j = i+1; j < numsSize; ++j)
    	{
			count++;
			if(nums[i] != nums[j])
    			ret += hammingDistance(nums[i], nums[j]);	
    	}
    }

    printf("count = %d\n", count);
    return ret;
}
#else
int totalHammingDistance(int* nums, int numsSize) {
    int ret=0;
    int temp=0;

    for(int i=0; i<32; i++)
    {
        temp = 0;
        for(int j = 0; j < numsSize; j++)
        {
            if((nums[j]&1) == 1)
            {
            	temp++;
            }
            nums[j] = nums[j]>>1;
        }

        ret = ret + temp * (numsSize-temp); //一的个数乘以非一的个数
    }
    return ret;
}
#endif

int main(int argc, char const *argv[])
{
	int nums[] = {4,14,2};

	// hammingDistance(9,6);

	printf("%d\n", totalHammingDistance(nums, sizeof(nums)/sizeof(int)));
	return 0;
}