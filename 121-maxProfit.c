/*
* @Author: cyang
* @Date:   2018-08-06 13:26:20
* @Last Modified by:   cy101
* @Last Modified time: 2020-03-09 21:51:48
*/

int maxProfit(int* prices, int pricesSize){
    int max = 0;

    for(int i = 0; i < pricesSize - 1; i++)
    {
        for(int j = i; j < pricesSize; j++)
        {
            int temp = prices[j] - prices[i];    
            if(temp > max)
            {
                max = temp;
            }
        }
    }

    return max;
}
