/*
*441. Arranging Coins
*/

#include <stdio.h>

int arrangeCoins(int n) {
    int idx;

    if(n == 0)return 0;
    if(n == 1)return 1;
    for(idx=1; idx<n; idx++)
    {
        n = n - idx;
        printf("n = %d, idx = %d\n",n,idx);
        if(n <= idx)
        {
            return idx;
        }
    }

    return idx;
}

int main()
{
    int num = 19;
    int ret;

    ret = arrangeCoins(num);
    printf("ret = %d\n",ret);

    return 0;
}
