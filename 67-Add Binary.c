/*
*67. Add Binary
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {

	int a_len = strlen(a);
	int b_len = strlen(b);

	int long_len = 0;
	int retStr_len = 0;
	int flag = 0;

	if ( a_len > b_len )
		long_len = a_len;
	else
		long_len = b_len;
	retStr_len = long_len+1+1;

	// printf("a_len = %d\n", a_len);
	// printf("b_len = %d\n", b_len);
	// printf("long_len = %d\n", long_len);
	char *retStr = (char *)malloc(retStr_len);

	for (int i = 0; i < long_len+1; ++i)
	{
		/* code */
		retStr[i] = '0';
	}
	retStr[long_len+1] = '\0';

	while( long_len )
	{
		printf("flag = %d\n", flag);

		if( (a[a_len-1] + b[b_len-1] == '1' + '1') && flag == 1) 
		{
			retStr[long_len] = '1';
			flag = 1;
		}
		else if( (a[a_len-1] + b[b_len-1] == '1' + '1') && flag == 0) 
		{
			retStr[long_len] = '0';
			flag = 1;	
		}
		else if( (a[a_len-1] + b[b_len-1] == '1' + '0') && flag == 1) 
		{
			retStr[long_len] = '0';
			flag = 1;
		}
		else if( (a[a_len-1] + b[b_len-1] == '1' + '0') && flag == 0) 
		{
			retStr[long_len] = '1';
			flag = 0;	
		}
		else if( (a[a_len-1] + b[b_len-1] == '0' + '0') && flag == 1) 
		{
			retStr[long_len] = '1';
			flag = 0;
		}
		else if( (a[a_len-1] + b[b_len-1] == '0' + '0') && flag == 0) 
		{
			retStr[long_len] = '0';
			flag = 0;	
		}

		if (a_len>1)
		{
			/* code */
			a_len--;
		}
		else
		{
			a[a_len-1] = '0';
		}

		if (b_len>1)
		{
			/* code */
			b_len--;
		}
		else
		{
			b[b_len-1] = '0';
		}

		long_len--;
	}

	if (flag == 1)
	{
		/* code */
		retStr[0] = '1';
	}

	// printf("retStr = %s\n", retStr);
	// printf("retStr_len = %d\n", retStr_len);

	while(retStr_len > 2)
	{
		if (*retStr != '0')
		{
			/* code */
			break;
		}
		retStr++;
		retStr_len--;
	}

	// printf("retStr_len = %d\n", retStr_len);
    return retStr;
}

int main(int argc, char const *argv[])
{
	/* code */
	// char a1[] = "11";
	// char a2[] = "1";
	char a1[] = "0000";
	char a2[] = "0";

	char *ret = NULL;

	ret = addBinary(a1,a2);
	
	printf("ret = %s\n", ret);

	if(ret != NULL)
	{
		printf("free\n");
		free(ret);
		ret = NULL;
	}

	return 0;
}