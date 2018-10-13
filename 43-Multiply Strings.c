/*
* @Author: cyang
* @Date:   2018-10-13 14:20:36
* @Last Modified by:   cyang
* @Last Modified time: 2018-10-13 15:49:58
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int length = len1 < len2 ? len2+1+1 : len1+1+1;  //+1: for add; +1: for '\0'

    // printf("length = %d\n", length);
    char *ret_str = (char *)malloc(length);
    memset(ret_str , 0, length);

    int flag = 0;
    int temp1, temp2;
    len1--;
    len2--;

    for (int i = 0; i < length-1; ++i)
    {
    	if (len1 >= 0)
    	{
    		temp1 = num1[len1] - '0';
    		len1--;
    	}
    	else
    	{
    		temp1 = 0;
    	}

    	if (len2 >= 0)
    	{
    		temp2 = num2[len2] - '0';
    		len2--;
    	}
    	else
    	{
    		temp2 = 0;
    	}

    	int sum = temp1 + temp2 + flag;
    	flag = sum / 10;
    	// printf("temp1 = %d, temp2 = %d, flag = %d\n", temp1, temp2, flag);

    	int idx = length - i - 2;
    	// printf("idx = %d\n", idx);
    	ret_str[idx] = (sum % 10) + '0';
    	// printf("num = %c, %d, %d, %d\n", ret_str[idx], ret_str[idx], sum % 10, sum);
    }

	/* 处理没有产生进位，第一位为 0 的情况 */
    if (ret_str[0] == '0')
    {
    	// printf("run there\n");
    	char *temp_str = (char *)(malloc)(length-1);
    	memcpy(temp_str, &ret_str[1], length-1);
    	free(ret_str);
    	ret_str = temp_str;
    }

    return ret_str;
}

/*
 * 0 <= num <= 81
 * buffer len must be 3
 */
void int2str(int num, char *buffer)
{
	char temp[3] = {0,0,0};
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	int idx = 0;
	int temp_num;

	do
	{
		temp_num = num % 10;
		num = num/10;	
		temp[idx++] = temp_num + '0';
	}while(num);

	for (int i = 0; i < idx; ++i)
	{
		buffer[i] = temp[idx - i - 1];
	}
}

/*
 * mutilply 10
 */
void expand10(char *num)
{
	int length = strlen(num);

	if (num[0] != '0')
	{
    	num[length] = '0';
    	num[length+1] = '\0';
	}
}

void expand10_N(int num, int count, char *buffer)
{
	int2str(num, buffer);
	int length = strlen(buffer);
	int i;

	if (buffer[0] != '0')
	{
		for (i = 0; i < count; ++i)
		{
			buffer[length+i] = '0';
		}
		buffer[length+i] = '\0';
	}
}

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int length = len1 + len2 + 1;  //+1: for '\0'

    // printf("length = %d\n", length);
    char *ret_str = (char *)malloc(length);
    char *temp_str = (char *)malloc(length);
    memset(ret_str , 0, length);
    memset(temp_str , 0, length);

    char temp_char[3];
    int flag = 0;
    int temp1, temp2;
    len1--;
    len2--;
    int len_min, len_max;
    char *num_min, *num_max;
    if(len1 <= len2)
    {
    	len_min = len1;
    	len_max = len2;
    	num_min = num1;
    	num_max = num2;
    }
    else
    {
    	len_min = len2;
    	len_max = len1;
    	num_min = num2;
    	num_max = num1;
    }

    int layer = 0;
    for (int i = len_min; i >= 0; i--)
    {
    	int cnt = 0;
    	for (int j = len_max; j >= 0; j--)
    	{
    		//multiply
    		temp2 = num_min[i] - '0';
    		temp1 = num_max[j] - '0';
    		// printf("temp1 = %d, temp2 = %d\n", temp1, temp2);

    		int product = temp1 * temp2;
    		expand10_N(product, cnt+layer, temp_str);
    		ret_str = addStrings(ret_str, temp_str); //ret_str * 10;
    		// printf("ret_str = %s\n", ret_str);

    		cnt++;
    	}
    	layer++;
    }

    if(temp_str)
    {
    	free(temp_str);
    }
    
    return ret_str;
}

int main(int argc, char const *argv[])
{
	const char *str1 = "123";
	const char *str2 = "999";

	char *ret_str = NULL;

#if 1
	ret_str = multiply((char *)str1, (char *)str2);
	printf("final_str = %s\n", ret_str);
	if(ret_str)
	{
		free(ret_str);
	}
#endif

	//module test
	// char temp[3] = {0,0,0};
	// int num = 19;

	// int2str(num, temp);
	// printf("%s\n", temp);

	// char temp[10] = {'1', '2'};
	// expand10(temp);

	// printf("%s, len = %d\n", temp, strlen(temp));

	// int num = 1;
	// int count = 50;
	// char temp_buffer[100];

	// expand10_N(num, count, temp_buffer);
	// printf("%s, strlen = %d\n", temp_buffer, strlen(temp_buffer));

	return 0;
}