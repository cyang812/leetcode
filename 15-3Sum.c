/*
* @Author: cyang
* @Date:   2018-08-06 16:26:59
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-15 14:55:12
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {

	int **return_array = (int **)malloc(sizeof(int *) * numsSize * (numsSize-1));

	qsort(nums, numsSize, sizeof(int), cmpfunc);

	int *start, *end; 
	int rerurn_size = 0;
	int temp = 0;

	for (int i = 0; i < numsSize-2; ++i)
	{
		if (nums[i-1] == nums[i] && i > 0)
			continue;

		printf("=======================================\n");	

		start = &nums[i+1];
		end = &nums[numsSize-1];

		while(start < end)
		{
			printf("%d %d %d %d \n", i, nums[i], *start, *end);
			temp = *start + *end + nums[i];
			if(temp == 0)
			{
				// printf("%d %d %d %d \n", i, nums[i], *start, *end);
				return_array[rerurn_size] = (int *)malloc(sizeof(int) * 3);
				return_array[rerurn_size][0] = nums[i];
				return_array[rerurn_size][1] = *start;
				return_array[rerurn_size][2] = *end;

				rerurn_size++;
				
				while(*start == *(start+1))
				{
					printf("+\n");
					start++;
				}
				#if 1 //ringht
				while((*end == *(end+1)) && (end != &nums[numsSize-1]))
				#else //wrong
				while(*end == *(end+1))	
				#endif
				{
					printf("-\n");
					end--;
				}

				start++;
				end--;
			}
			else if (temp < 0)
			{
				start++;
			}
			else // > 0
			{
				end--;
			}

			printf("%p, %p\n", start, end);		
		}
	}

	*returnSize = rerurn_size;
	printf("rerurn_size = %d\n", rerurn_size);

	return return_array;
}

int nums[] = {1, -4, -4, 2, 0, 0, -2, 3, 3, -3, -4};

int main(int argc, char const *argv[])
{
	// int nums[] = {-1, 0, 1, 2, -1, -4};	
	// int nums[] = {0, 0, 0, 0};	
	// int nums[] = {1, -1, -1, 0};
	// int nums[] = {-2, 0, 0, 2, 2};
	// int nums[] = {-2, 0, 1, 1, 2};
	// int nums[] = {1, -4, -4, 2, 0, 0, -2, 3, 3, -3, -4};

	int numsSize = sizeof(nums)/sizeof(int);

	int returnSize = 0;
	int **return_array = NULL;

	return_array = threeSum(nums, numsSize, &returnSize);

	printf("\n");
	if(return_array == NULL)
		return 0;

	for (int i = 0; i < returnSize; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", return_array[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < returnSize; ++i)
	{
		free(return_array[i]);
	}

	// system("pause");

	return 0;
}