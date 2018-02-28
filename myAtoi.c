/*
*8. String to Integer (atoi)
*/

#include <stdio.h>

int myAtoi(char* str) {
    
	long long ret = 0;
	int tmp = 0;
	int flag = 0;

	while(*str)
	{
		tmp = *str - '0';	

		if(flag == 0)
		{		
			if(*str == ' ')
			{

			}
			else if(*str == '+')
			{
				flag = 1;
			}
			else if(*str == '-')
			{
				flag = 2;
			}
			else if(tmp <= 9 && tmp >= 0)
			{
				ret = ret*10 + tmp;
			}
			else
				break;
		}
		else
		{
			if(tmp <= 9 && tmp >= 0)
			{
				ret = ret*10 + tmp;
			}
			else
				break;
		}

		str++;
	}

	if(flag == 2)
		ret = -ret;

	if(ret > (int)(0x7fffffff))
		return 0x7fffffff;

	if(ret < (int)(0x80000000))
		return 0x80000000;

	printf("flag = %d\n", flag);

	return ret;
}


int main(int argc, char const *argv[])
{
	/* code */
	// char str[] = "2147483648";
	char str[] = "123    456";

	int ret = 0;

	ret = myAtoi(str);

	printf("ret = %d\n", ret);

	return 0;
}