/*
*67. Add Binary
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int getBinary(char *a)
{
	unsigned int ret = 0;
	while(*a)
	{
		if(*a == '1' || *a == '0')
		{
			ret = ret*2 + *a-'0';
		}
		a++;
	}

	return ret;
}

unsigned int dec2bin(unsigned int dec)
{
	unsigned int ret;

	while(dec%2)
	{
		
	}
}

char* addBinary(char* a, char* b) {

	char *retStr = (char *)malloc(10);

	unsigned int aVal = getBinary(a);
	unsigned int bVal = getBinary(b);
	unsigned int cVal = aVal + bVal;

	printf("a = %b\n", aVal);
	printf("b = %b\n", bVal);
    
	while(cVal)
	{
		if(cVal/2)
	}

    return retStr;
}

int main(int argc, char const *argv[])
{
	/* code */
	char a1[] = "11";
	char a2[] = "1";

	char *ret = NULL;

	ret = addBinary(a1,a2);

	// printf("ret = %s\n", ret);

	if(ret != NULL)
	{
		printf("free\n");
		free(ret);
		ret = NULL;
	}

	return 0;
}