/*
*326. Power of Four
* three ways to solution this problem
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define solution 2

bool isPowerOfThree(int n) {

  #if solution==1
  //循环迭代
    while(n)
    {
        if(n==1)return true;
        if(n%4 != 0)
            return false;
        n /= 4;
        if(n == 1)
            return true;
    }
    return false;
  #elif solution==2
  //32位数中最大的4的次方数
    if(n <= 0)return false;
    if(4294967296%n == 0)
    {
        if((int)(log10(n)/log10(2)) % 2 == 0)
            return true;
        else
            return false;
    }
    else
        return false;
  #elif solution==3
  //对数换底公式
  //使用 a-(int)a == 0; 来判断a是否为整数
    double res;
    res = log10(n)/log10(4);
    if(res- (int)res == 0)
        return true;
    else
        return false;
  #endif
}

int main()
{
    int num = 32;
    bool res = false;

    res = isPowerOfThree(num);
    printf("res = %d\n",res);

    return 0;
}
