/*
* @Author: cyang
* @Date:   2018-10-13 15:55:01
* @Last Modified by:   cyang
* @Last Modified time: 2018-10-13 16:48:32
*/

#include <stdio.h>
#include <math.h>

int reachNumber(int target) {
    int cnt = 0;
    int temp = 0;

    target = abs(target);
    if (target == 0)
    	return 0;
#if 0
	while(1)
	{
		cnt++;

    	if( (temp+cnt) > target)
    	{
    		temp -= cnt;
    	}
    	else //if(temp < target)
    	{
    		temp += cnt;
    	}

    	// printf("temp = %d\n", temp);
    	if(temp == target)
    		break;	

    	// for debug
    	if(cnt > 1000)
    	{
    		printf("over steps\n");
    		break;
    	}
	}	

    return cnt;
#else
	while(temp < target)
	{
		cnt++;
		temp += cnt;
	}

	int dt = temp - target;
	if (dt % 2 == 0)
	{
		return cnt;
	}
	else
	{
		if (cnt % 2 == 0)
		{
			return cnt + 1;
		}
		else
		{
			return cnt + 2;
		}
	}
#endif
}

int main(int argc, char const *argv[])
{
#if 0 
	int num = 4;
	int ret = reachNumber(num);
	printf("need %d steps\n", ret);
#else
	for (int i = 0; i < 100; ++i)
	{
		int temp1, temp2;

		temp1 = reachNumber(i);
		temp2 = reachNumber(-i);

		if (temp1 != temp2)
		{
			printf("idx = %d\n", i);
		}
		else
		{
			printf("idx %d need %d steps\n", i, temp1);
		}
	}
#endif
	return 0;
}