/*
* @Author: cyang
* @Date:   2018-09-28 15:05:20
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 10:22:28
*/

#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
	int cnt = 0;
	int left = 0;
	int res = 1;
	
	if (k <= 1)
	{
		return 0;
	}

	for (int i = 0; i < numsSize; ++i)
	{
		res *= nums[i];
		#if 0
		if(res < k)
		{
			cnt++;
			for (int j = i+1; j < numsSize; ++j)
			{
				res *= nums[j];
				if (res < k)
				{
					cnt++;
				}
				else
					break;
			}
		}
		#else
		while(res >= k)
		{
			res /= nums[left++];
		}
		// printf("%d\n", i-left+1);	
		cnt += i - left + 1;
		#endif
	}

	return cnt;
}

int main(int argc, char const *argv[])
{
	int nums[] = {10, 5, 2, 6};
	int k = 100;

	int res = 0;

	res = numSubarrayProductLessThanK(nums, sizeof(nums)/sizeof(nums[0]), k);
	printf("res = %d\n", res);

	return 0;
}