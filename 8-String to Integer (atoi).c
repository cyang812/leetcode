/*
*8. String to Integer (atoi)
*/

#include <stdio.h>

int myAtoi(char* str) {
    
	long long ret = 0;
	int tmp = 0;
	int flag = 0;
	int err = 0;
	int cnt = 0;

	while(*str && err==0)
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
				cnt++;
				flag = 1;
			}
			else
				break;
		}
		else
		{
			if(tmp <= 9 && tmp >= 0)
			{
				ret = ret*10 + tmp;
				cnt++;
			}
			else
			{
				err = 1;
			}	
		}

		str++;
	}

	printf("tmp = %d\n", ret);

	if(flag == 2)
		ret = -ret;

	if( (ret > (int)(0x7fffffff)) || (flag==1 && cnt>10) )
		ret = 0x7fffffff;

	if( (ret < (int)(0x80000000)) || (flag==2 && cnt>10) )
		ret = 0x80000000;

	printf("flag = %d\n", flag);
	printf("err = %d\n", err);
	printf("cnt = %d\n", cnt);

	return ret;
}


int main(int argc, char const *argv[])
{
	/* code */
	// char str[] = "2147483648";
	// char str[] = "123    456";
	// char str[] = "9223372036854775809";
	char str[] = "-9223372036854775809";

	int ret = 0;

	ret = myAtoi(str);

	printf("ret = %d\n", ret);

	return 0;
}