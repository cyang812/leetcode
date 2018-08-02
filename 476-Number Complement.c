/*
* @Author: cyang
* @Date:   2018-08-02 15:41:53
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-02 16:58:22
*/

#include <stdio.h>
#include <stdint.h>

int findComplement(int num) {
	int ret = 0;
	int cnt = 0; //前导零计数
	int temp = ~num;

	ret = temp;

	//__asm(clz Rd, Rm) 计算前导零计数
	/*
	int result;
    asm("clz %0, %1 ": "=r"(result) : "r"(value) );
    return result;
	*/
	while(temp&0x80000000)
	{
		temp <<= 1;	
		cnt++;   
	}

	ret <<= cnt;
	ret >>= cnt;

	printf("clz: %d\n", cnt);
	return ret;
}

int main(int argc, char const *argv[])
{
	int i = 0;
	printf("%d\n", findComplement(i));	

	return 0;
}