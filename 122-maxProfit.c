/*
* @Author: cy101
* @Date:   2020-03-09 22:09:06
* @Last Modified by:   cyang
* @Last Modified time: 2020-03-09 23:01:38
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
	int sum = 0;

    for (int i = 0; i < pricesSize-1; ++i)
    {
    	if (prices[i+1] > prices[i])
    	{
    		sum += prices[i+1] - prices[i];
    	}
    }

    return sum;
}

int main(int argc, char const *argv[])
{
	int prices[] = {7,1,5,3,6,4};

	int sum = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));

	printf("maxProfit = %d\n", sum);

	return 0;
}