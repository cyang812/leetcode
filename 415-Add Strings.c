/*
* @Author: cyang
* @Date:   2018-10-13 11:44:26
* @Last Modified by:   cyang
* @Last Modified time: 2018-10-13 14:17:13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
/* 字符长度限制在 64 位内可行 */
typedef unsigned long long uint64_t;

uint64_t str2u64(const char *str)
{
	uint64_t ret = 0;
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		ret = ret * 10 + (str[i] - '0');
	}

	return ret;
}

void u642str(uint64_t num, char *buffer)
{
	char temp[32];
	int idx = 0;
	uint64_t temp_num;

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

char* addStrings(char* num1, char* num2) {
    int ret = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int length = len1 < len2 ? len2+1+1 : len1+1+1; 

    char *ret_str = (char *)malloc(length);
    memset(ret_str , 0, length);

    uint64_t count = str2u64(num1) + str2u64(num2);
    printf("count = %d\n", count);

	u642str(count, ret_str);	    	
    return ret_str;
}

int main(int argc, char const *argv[])
{
	const char *str1 = "0";
	const char *str2 = "0";

#if 1
	char *ret_str = NULL;

	ret_str = addStrings((char *)str1, (char *)str2);
	printf("ret_str = %s\n", ret_str);
	if(ret_str)
	{
		free(ret_str);
	}
#endif

	// int temp = 0;
	// temp = str2int(str1);
	// printf("%d\n", temp);

	// char temp_char[50];
	// memset(temp_char, 0, sizeof(temp_char));
	// int2str(123, temp_char);

	// printf("%s\n", temp_char);
	return 0;
}
#else
/* 字符串长度不受限制 */
char* addStrings(char* num1, char* num2) {
    int ret = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int length = len1 < len2 ? len2+1+1 : len1+1+1;  //+1: for add; +1: for '\0'

    printf("length = %d\n", length);
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
    	printf("run there\n");
    	char *temp_str = (char *)(malloc)(length-1);
    	memcpy(temp_str, &ret_str[1], length-1);
    	free(ret_str);
    	ret_str = temp_str;
    }

    return ret_str;
}

int main(int argc, char const *argv[])
{
	const char *str1 = "9";
	const char *str2 = "99";

	char *ret_str = NULL;

	ret_str = addStrings((char *)str1, (char *)str2);
	printf("ret_str = %s\n", ret_str);
	if(ret_str)
	{
		free(ret_str);
	}

	return 0;
}
#endif
