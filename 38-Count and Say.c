/*
* 38. Count and Say
*
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrcat(char *dst,const char *src) //用自己的方式实现strcat函数功能
{
    char *p=dst;  //下面的操作会改变目的指针指向，先定义一个指针记录dst
    while(*p!='\0')p++;
    while(*src != '\0')*p++=*src++;
    *p='\0';

    return p;  //dst现在指向拼接后的最后一位字符，在这里返回dst，会出现错误
}
#if 0
char* countAndSay1(int n) {

    //char *s = (char*)malloc((n)*sizeof(char));
    static char s[200] = "";
    char*strPtr = s;
    char temp[30];
    int i,idx = 1;
    int count = 0;

    if(n == 1)return;
    if(n == 2)
    {
        strPtr = "11";
        printf("n==1\n");
        //printf("s = %d\n",strlen(s));
        //sprintf(temp,"%d%d",n,n);
        return strPtr;
    }
    else
    {

        strPtr = countAndSay(n-1);
        printf("++++++++++++++++++begin+++++++++++++++++++++++\n");
        printf("str =%s , strlen =%d\n",strPtr,strlen(strPtr));
        for(i=0,idx=1,count=0; count<strlen(strPtr);i++ )
        {
            printf("loop\n");
            //if((strPtr[i]-'0') == (strPtr[i+1]-'0'))
            if((strPtr[i]) == (strPtr[i+1]))
            {
                printf("idx++\n");
                idx++;
            }else
            {
                printf("strPtr[%d] =%d, strPtr[%d] =%d\n",i,strPtr[i],i+1,strPtr[i+1]);
                sprintf(temp,"%d%c",idx,(strPtr[i]));
                printf("idx =%d, s[i] =%c, temp =%s \n",idx,strPtr[i],temp);

                //toDo:strcat
                strcat(s,temp);
                //strcpy(s,temp);
                count+=idx;
                idx = 1;
            }
        }
    }
    strPtr = s;
    printf("s =%s,length =%d\n",s,strlen(s));
    return strPtr;
}
#endif
char* countAndSay(int n) {

    char * retstr = "1";
    if( n == 1 ) return retstr;
    
	char *cur = (char *)malloc(2), *tmp;
	cur[0] = '1';
	cur[1] = 0;

	int len, idx, j, count;
	for(int i = 2; i <= n; ++i)
	{
		len = strlen(cur);
		tmp = malloc(len * 3);
		memset(tmp, 0, len * 3);
		count = 1;
		for(idx = 1, j = 0; idx < len; ++idx)
		{
			if(cur[idx] == cur[idx-1])
        	{
            	++count;
        	}
			else
        	{
            	tmp[j++] = '0' + count;
            	tmp[j++] = cur[idx-1];
            	count = 1;
        	}
		}//end of for
		tmp[j++] = '0' + count;
    	tmp[j++] = cur[len-1];
		free(cur);
		cur = tmp;
	}
	return cur;
}

int main(){

    int a = 5;
    char *str;

    str = countAndSay(a);

    printf("str =%s\n",str);

    return 0;
}
