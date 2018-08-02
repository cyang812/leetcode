/*
* @Author: cyang
* @Date:   2018-08-02 14:31:30
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-02 14:34:25
*/

#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
	int ret = 0;

	for (int i = 0; i < 32; ++i)
 	{
		/* code */
 		if(n & 0x01)
 			ret++;

 		n = n >> 1;
 	} 	

 	return ret;
}

int main(int argc, char const *argv[])
{
	int i = 11;
	printf("%d\n", hammingWeight(i));
	return 0;
}
