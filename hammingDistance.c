#include <stdio.h>
#include <stdint.h>

int hammingDistance(int x, int y) {

    int z;
	int sum=0;

	z = x^y;
	//printf("z:%d\n",z);
	
	while(z!=0)
	{
		if(z%2 == 1)
			sum++;
			
		z = z/2;
	}

	return sum;
}

int main()
{
	int x = 3;
	int y = 9;
	
	int distance;
	distance  = hammingDistance(x,y);
	printf("distance:%d\n",distance);

	return 0;
}