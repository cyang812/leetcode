/*
* 507. Perfect Number
*/

#include <stdio.h>
#include <stdbool.h>

//time limit
bool checkPerfectNumber1(int num) {

	int temp = 0;
	int i;

	for(i=1; i<num; i++)
	{
		if(num%i == 0)
		{
            temp += i;
		}
	}

	printf("temp = %d\n",temp);

	if(temp == num)
	{
		return true;
	}
	else
		return false;
}


bool checkPerfectNumber(int num) {

	int temp = 1;
	int i;
    int maxNum;

    if(num <= 1)
        return false;

    maxNum = num;
	for(i=2; i<maxNum; i++)
	{
		if(num%i == 0)
		{
            maxNum = num/i;
			temp += i;
			temp += maxNum;
		}

		if(temp > num)
        {
           break;
        }
	}

	printf("temp = %d\n",temp);

	if(temp == num)
	{
		return true;
	}
	else
		return false;
}

int main()
{
   	int num = 99999993;
   	//int num = 28;
   	bool ret = false;

    ret = checkPerfectNumber(num);
    printf("ret = %d\n",ret);

    return 0;
}
