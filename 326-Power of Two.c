/*
*326. Power of Two
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
        if(n%2 != 0)
            return false;
        n /= 2;
        if(n == 1)
            return true;
    }
    return false;
  #elif solution==2
  //32位数中最大的3次方数
    if(n <= 0)return false;
    if(2147483648%n == 0)
        return true;
    else
        return false;
  #elif solution==3
  //对数换底公式
  //使用 a-(int)a == 0; 来判断a是否为整数
    double res;
    res = log10(n)/log10(2);
    if(res- (int)res == 0)
        return true;
    else
        return false;
  #endif
}

int main()
{
    int num = 64;
    bool res = false;

    res = isPowerOfThree(num);
    printf("res = %d\n",res);

    return 0;
}
