/*
* @Author: cyang
* @Date:   2018-09-28 13:46:39
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-28 15:01:23
*/

#include <stdio.h>

bool isPrime(int n)
{
	if(n == 0 || n == 1) return false;
	for (int i = 2; i <= n/2; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}

	return true;
}

bool isPalindrome(int n)
{
	int bak = n;
	int ret = 0;

	do
	{
		ret *= 10;
		ret += bak%10;
		bak = bak/10;
	}while(bak);

	return ret == n;
}

int primePalindrome(int N) {
    
	int ret = N;
	if (N == 1)
	{
		return 2;
	}
	else if(N == 2)
	{
		return 2;
	}

	if (1e7 <= N && N <= 1e8)
		return 100030001;

	if ( N % 2 == 0)
	{
		ret++;
	}

	while(1)
	{
		if( (isPalindrome(ret)) && (isPrime(ret)) )
			break;
		else
			ret += 2;
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	int a = 2;
	int res;

	res = primePalindrome(a);
	printf("%d\n", res);
		
	// for (int i = 0; i < 200; ++i)
	// {
	// 	printf("%d, %d\n", i, isPalindrome(i));
	// }	

	return 0;
}