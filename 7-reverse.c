/*
*7. Reverse Integer
*/

#include <stdio.h>

int reverse(int x) {
    long long ret = 0;

    while(x)
    {
		ret = ret*10 + x%10;
		x = x/10;
    }

    printf("temp = %d\n", ret);

    if(ret <= (int)(0x7fffffff) && ret >= (int)(0x80000000))
    	return ret;
    else
    	return 0;
    
}

int main(int argc, char const *argv[])
{
	/* code */

	// int a = -10;
	// int a = 1534236469;
	int a = 123;
	int ret;

	ret = reverse(a);

	printf("ret = %d\n", ret);

	return 0;
}