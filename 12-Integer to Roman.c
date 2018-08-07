/*
* @Author: cyang
* @Date:   2018-08-06 13:56:50
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-06 14:21:34
*/

#include <stdio.h>
#include <stdlib.h>

/*
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000

 IV            4
 IX            9
 XL            40
 XC            90
 CD            400
 CM            900
*/

/*
 * num: [1,3999]
 */
char* intToRoman(int num) {
	char *ret_str = (char *)malloc(20);
	int idx = 0;

	int a,b,c,d;
	
	a = num / 1000;
	b = (num - a * 1000) / 100;
	c = (num - (a * 1000) - (b * 100)) / 10;
	d = (num - (a * 1000) - (b * 100) - (c * 10));

	printf("a,b,c,d = %d,%d,%d,%d\n", a,b,c,d);

	if (a)
	{
		while(a--)
		{
			ret_str[idx++] = 'M';
		}
	}

	if (b)
	{
		if (b == 4)
		{
			ret_str[idx++] = 'C';
			ret_str[idx++] = 'D';
		}
		else if(b == 9)
		{
			ret_str[idx++] = 'C';
			ret_str[idx++] = 'M';				
		}
		else
		{
			if(b >= 5)
			{
				ret_str[idx++] = 'D';
				b -= 5;
			}	

			while(b--)
			{
				ret_str[idx++] = 'C';
			}
		}
	}

	if (c)
	{
		if (c == 4)
		{
			ret_str[idx++] = 'X';
			ret_str[idx++] = 'L';
		}
		else if(c == 9)
		{
			ret_str[idx++] = 'X';
			ret_str[idx++] = 'C';				
		}
		else
		{
			if(c >= 5)
			{
				ret_str[idx++] = 'L';
				c -= 5;
			}	

			while(c--)
			{
				ret_str[idx++] = 'X';
			}
		}
	}

	if (d)
	{
		if (d == 4)
		{
			ret_str[idx++] = 'I';
			ret_str[idx++] = 'V';
		}
		else if(d == 9)
		{
			ret_str[idx++] = 'I';
			ret_str[idx++] = 'X';				
		}
		else
		{
			if(d >= 5)
			{
				ret_str[idx++] = 'V';
				d -= 5;
			}	

			while(d--)
			{
				ret_str[idx++] = 'I';
			}
		}
	}

	ret_str[idx] = '\0';

	printf("idx = %d\n", idx);
	return ret_str;
}

int main(int argc, char const *argv[])
{
	int num = 1994;//999;
	char *roman_str = NULL;

	roman_str = intToRoman(num);
	printf("%s\n", roman_str);

	if (roman_str)
	{
		free(roman_str);
	}

	return 0;
}