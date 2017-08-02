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
  //ѭ������
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
  //32λ��������4�Ĵη���
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
  //�������׹�ʽ
  //ʹ�� a-(int)a == 0; ���ж�a�Ƿ�Ϊ����
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
