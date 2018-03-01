/*
*556. Next Greater Element III
*/

#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}

int nextGreaterElement(int n) {
    
    int m = n;
    int nums[10] = {0};
    int numSize = 0;
    long long ret_val = -1;
    int temp1,temp2,temp3;

    while(m)
    {
    	nums[numSize++] = m%10;
    	m = m/10;
    }

    // printf("numSize = %d\n", numSize);

    // for (int i = 0; i < numSize; ++i)
    // {
    // 	printf("none = %d\n", nums[i]);
    // }

	for(int i = 0; i<numSize-1; i++)
	{
		if(nums[i] > nums[i+1])
		{
			temp1 = nums[i];
			temp2 = i;
			for(int x = 0; x < i; x++)
			{
				if( (nums[x] > nums[i+1]) && (nums[x] < temp1) )
				{
					temp1 = nums[x];
					temp2 = x;
				}
			}
			printf("temp1 = %d\n", temp1);
			printf("temp2 = %d\n", temp2);
			nums[temp2] = nums[i+1];
			nums[i+1] = temp1;
			ret_val = 0;

		    // for (int i = 0; i < numSize; ++i)
		    // {
		    // 	printf("none = %d\n", nums[i]);
		    // }

			bubble_sort(nums,i+1);

			break;
		}
	}

	// for (int i = 0; i < numSize; ++i)
 //    {
 //    	printf("after = %d\n", nums[i]);
 //    }

	if(ret_val == 0)
	{
		for(int z = numSize-1; z>=0; z--)
		{
			ret_val = ret_val*10 + nums[z];
		}
	}
	if (ret_val > (int)0x7fffffff)
	{
		ret_val = -1;
	}

    return ret_val;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a1 = 12;
	int a2 = 230241;
	int a3 = 12443322;
	int a4 = 1999999999;

	int ret = 0;

	ret = nextGreaterElement(a4);

	printf("ret = %d\n", ret);

	return 0;
}