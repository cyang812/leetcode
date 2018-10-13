/*
* @Author: cyang
* @Date:   2018-10-13 15:55:01
* @Last Modified by:   cyang
* @Last Modified time: 2018-10-13 17:30:36
*/


/*
 *分析如下：首先一次相加直到和大于目标，比较差值，
 *	       如果是偶数，说明只需要将几个数由加号变为减号（里外里2倍，所以一定是偶数），
 *		   若是奇数，就要想办法制造1，减去一个奇数加上下一个偶数即可，
 *		   所以如果当前n是个奇数，就需要加上下一个偶数，如果当前是个偶数就需要减去下一个奇数，加上下一个偶数。
 *
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
	int ret = 0;
	if (dt % 2 == 0)
	{
		ret = cnt;
	}
	else
	{
		if (cnt % 2 == 0)
		{
			ret = cnt + 1;
		}
		else
		{
			ret = cnt + 2;
		}
	}
	printf("target = %d, temp = %d, dt = %d, cnt = %d, ",target, temp, dt, cnt);
	printf("need %d\n", ret);

	return ret;
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
		// printf("need %d\n", temp1);
	}
#endif
	return 0;
}