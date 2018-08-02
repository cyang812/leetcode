/*
* @Author: cyang
* @Date:   2018-08-02 14:36:52
* @Last Modified by:   cyang
* @Last Modified time: 2018-08-02 14:40:11
*/

#include <stdio.h>
#include <stdint.h>

int hammingDistance(int x, int y) {
    int ret = 0;

    for (int i = 0; i < 32; ++i)
    {
    	/* code */
    	int a = x & 0x01;
    	int b = y & 0x01;

    	if(a != b)
    		ret++;

    	x >>= 1;
    	y >>= 1;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	int x = 2;
	int y = 8;

	printf("%d\n", hammingDistance(x,y));

	return 0;
}