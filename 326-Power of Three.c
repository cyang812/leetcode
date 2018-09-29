/*
*326. Power of Three
* three ways to solution this problem
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define solution 3

bool isPowerOfThree(int n) {

  #if solution==1
  //循环迭代
    while(n)
    {
        if(n==1)return true;
        if(n%3 != 0)
            return false;
        n /= 3;
        if(n == 1)
            return true;
    }
    return false;
  #elif solution==2
  //32位数中最大的3次方数
    if(n <= 0)return false;
    if(1162261467%n == 0)
        return true;
    else
        return false;
  #elif solution==3
  //对数换底公式
  //使用 a-(int)a == 0; 来判断a是否为整数
    double res;
    res = log10(n)/log10(3);
    if(res- (int)res == 0)
        return true;
    else
        return false;
  #endif
}

int main()
{
    int num = 4782968;
    bool res = false;

    res = isPowerOfThree(num);
    printf("res = %d\n",res);

    return 0;
}
