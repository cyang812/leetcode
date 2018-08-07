/*
* @Author: cyang
* @Date:   2018-08-06 14:29:00
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-06 16:15:23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *tab0[] = {
	"Zero",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten"
};

const char *tab1[] = {
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Nineteen"
};

const char *tab2[] = {
	"Twenty",
	"Thirty",
	"Forty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety"
};

const char *tab3[] = {
	"Hundred",
	"Thousand",
	"Million",
	"Billion"
};

int num_split(int num, char *ret_str)
{
	int a,b,c;
	int idx = 0;

	a = num / 100;
	b = (num - (a * 100)) / 10;
	c = (num - (a * 100) - (b * 10));
	printf("num_split a,b,c = %d,%d,%d\n", a,b,c);

	if (a)
	{
		strcpy(&ret_str[idx], tab0[a]);
		idx += strlen(tab0[a]);
		ret_str[idx] = ' ';
		idx += 1;

		strcpy(&ret_str[idx], tab3[0]);  //hundred
		idx += strlen(tab3[0]);
		ret_str[idx] = ' ';
		idx += 1;		
	}

	if (b)
	{
		if (b == 1)
		{
			strcpy(&ret_str[idx], tab1[c]);
			idx += strlen(tab1[c]);
			ret_str[idx] = ' ';
			idx += 1;
		}	
		else
		{
			b = b - 2;
			strcpy(&ret_str[idx], tab2[b]);
			idx += strlen(tab2[b]);
			ret_str[idx] = ' ';
			idx += 1;

			if (c)
			{
				strcpy(&ret_str[idx], tab0[c]);
				idx += strlen(tab0[c]);
				ret_str[idx] = ' ';
				idx += 1;
			}
		}	
	}
	else if (c)
	{
		strcpy(&ret_str[idx], tab0[c]);
		idx += strlen(tab0[c]);
		ret_str[idx] = ' ';
		idx += 1;	
	}

	return idx;
}

char* numberToWords(int num) {
    char *ret_str = (char *)malloc(200);
   	int idx = 0;

   	int a,b,c,d;
   	int t1,t2,t3;
   	t1 = t2 = t3 = 0;

   	int str_len = 0;

	a = num / 1000000000;
	b = (num -  a * 1000000000) / 1000000;
	c = (num - (a * 1000000000) - (b * 1000000)) / 1000;
	d = (num - (a * 1000000000) - (b * 1000000) - (c * 1000));
	printf("a,b,c,d = %d,%d,%d,%d\n", a,b,c,d);

	if (num == 0) 
	{
		strcpy(ret_str, tab0[0]);
		idx += strlen(tab0[0]);	
		ret_str[idx] = ' ';
		idx += 1;
	}

	if (a) //Billion
	{
		strcpy(ret_str, tab0[a]);
		idx += strlen(tab0[a]);
		ret_str[idx] = ' ';
		idx += 1;

		strcpy(&ret_str[idx], tab3[3]);
		idx += strlen(tab3[3]);
		ret_str[idx] = ' ';
		idx += 1;
	}

	if (b) //Million
	{
		str_len = num_split(b, &ret_str[idx]);
		// printf("b str_len = %d\n", str_len);
		idx += str_len;

		strcpy(&ret_str[idx], tab3[2]);
		idx += strlen(tab3[2]);
		ret_str[idx] = ' ';
		idx += 1;
	}

	if (c) //Thousand
	{
		str_len = num_split(c, &ret_str[idx]);
		// printf("c str_len = %d\n", str_len);
		idx += str_len;

		strcpy(&ret_str[idx], tab3[1]);
		idx += strlen(tab3[1]);
		ret_str[idx] = ' ';
		idx += 1;
	}

	if (d)
	{
		str_len = num_split(d, &ret_str[idx]);
		idx += str_len;
	}

	ret_str[idx-1] = '\0';
	printf("idx = %d\n", idx);
	return ret_str;
}

int main(int argc, char const *argv[])
{
	int num = 20;//1234567891;

	char *ret_str = NULL;

	ret_str = numberToWords(num);

	if (ret_str)
	{
		printf("%s\n", ret_str);

		free(ret_str);
		ret_str = NULL;
	}

	return 0;
}
