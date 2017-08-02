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
  //ѭ������
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
  //32λ��������3�η���
    if(n <= 0)return false;
    if(2147483648%n == 0)
        return true;
    else
        return false;
  #elif solution==3
  //�������׹�ʽ
  //ʹ�� a-(int)a == 0; ���ж�a�Ƿ�Ϊ����
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
