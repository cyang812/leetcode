/*
* @Author: cyang
* @Date:   2018-08-06 13:26:20
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-06 13:54:12
*/

#include <stdio.h>

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

int romanToInt(char* s) {
	int ret_num = 0;

	while(*s)
	{
		if(*s == 'I')
		{
			if(*(s+1) == 'V')
			{
				ret_num += 4;
				s++;
			}
			else if(*(s+1) == 'X')
			{
				ret_num += 9;
				s++;
			}
			else
			{
				ret_num += 1;
			}	
		}
		else if(*s == 'V')
		{
			ret_num += 5;
		}
		else if(*s == 'X')
		{
			if(*(s+1) == 'L')
			{
				ret_num += 40;	
				s++;
			}
			else if(*(s+1) == 'C')
			{
				ret_num += 90;
				s++;
			}
			else
			{
				ret_num += 10;
			}	
		}
		else if(*s == 'L')
		{
			ret_num += 50;
		}
		else if(*s == 'C')
		{
			if(*(s+1) == 'D')
			{
				ret_num += 400;	
				s++;		
			}
			else if(*(s+1) == 'M')
			{
				ret_num += 900;	
				s++;
			}
			else
			{
				ret_num += 100;
			}	
		}
		else if(*s == 'D')
		{
			ret_num += 500;
		}
		else if(*s == 'M')
		{
			ret_num += 1000;
		}

		s++;
		printf("ret_num = %d\n", ret_num);
	}

	return ret_num;
}

int main(int argc, char const *argv[])
{
	// const char *roman_str = "LVIII";
	// const char *roman_str = "MCMXCIV";
	const char *roman_str = "DCXXI";
	int num = 0;

	num = romanToInt((char *)roman_str);
	printf("num = %d\n", num);
	
	return 0;
}