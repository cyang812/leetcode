/*
* @Author: cyang
* @Date:   2018-08-02 13:50:57
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-02 14:26:42
*/

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
	uint32_t ret = 0;	
	uint32_t temp = 0;

	for (int i = 0; i < 32; ++i)
	{
		temp = n & 0x01;
		n = n >> 1;
		printf("%d ", temp);

		ret = ret << 1;
		ret = ret | temp;
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	uint32_t x = 43261596;
	uint32_t y = 0;

	y = reverseBits(x);
	printf("\n%d\n", y);

	reverseBits(y);

	printf("0x%08x\n", x);
	printf("0x%08x\n", y);

	return 0;
}