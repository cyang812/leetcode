#include <stdio.h>
#include <math.h>

int findComplement(int num) {
    
	int temp,index=0;
	int sum=0;	

	while(num/2)
	{
		temp = num%2;
		sum+=(!temp)*pow(2,index);
		index++;
		num/=2;
	}

	return sum;
}

int main()
{
	int a = 4;
	int b;

	b = findComplement(a);
	printf("b=%d\n",b);

	return 0;
}