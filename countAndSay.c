/*
* 38. Count and Say
*
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrcat(char *dst,const char *src) //���Լ��ķ�ʽʵ��strcat��������
{
    char *p=dst;  //����Ĳ�����ı�Ŀ��ָ��ָ���ȶ���һ��ָ���¼dst
    while(*p!='\0')p++;
    while(*src != '\0')*p++=*src++;
    *p='\0';

    return p;  //dst����ָ��ƴ�Ӻ�����һλ�ַ��������ﷵ��dst������ִ���
}


char* countAndSay(int n) {

    //char *s = (char*)malloc((n)*sizeof(char));
    char s[200] = " ",*strPtr = s;
    char temp[30];
    int i,idx = 1;
    int count = 0;

    if(n == 1)
    {
        strPtr = "11";
        printf("n==1\n");
        //printf("s = %d\n",strlen(s));
        return strPtr;
    }
    else
    {
        strPtr = countAndSay(n-1);
        printf("str = %s , strlen = %d\n",strPtr,strlen(strPtr));
        for(i=0; count<strlen(strPtr);i++ )
        {
            printf("loop\n");
            if(strPtr[i] == strPtr[i+1])
            {
                printf("idx++\n");
                idx++;
            }else
            {
                sprintf(temp,"%d%c",idx,strPtr[i]);
                printf("idx = %d, s[i] = %c, temp = %s \n",idx,strPtr[i],temp);

                //toDo:strcat
                strcat(s,temp);
                count+=idx;
                idx = 1;
            }
        }
    }
    strPtr = s;
    printf("s = %s\n",s);
    return strPtr;

}


int main(){

    int a = 3;
    char *str;

    str = countAndSay(a);

    printf("str = %s\n",str);
    return 0;
}
