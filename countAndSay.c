/*
* 38. Count and Say
*
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* countAndSay(int n) {

    //char *s = (char*)malloc((n)*sizeof(char));
    char *s = (char*)malloc((10)*sizeof(char));
    char temp[3];
    int i,idx;
    int count = 0;

    if(n == 1)
    {
        s = "11";
        //printf("n==1\n");
        //printf("s = %d\n",strlen(s));
        return s;
    }
    else
    {
        s = countAndSay(n-1);
        printf("str = %s , strlen = %d\n",s,strlen(s));
        for(i=0,count=0; count<strlen(s);i++ )
        {
            idx=1;
            if(s[i] == s[i+1])
            {
                idx++;
            }else
            {
                sprintf(temp,"%d%d",idx,s[i]);
                printf("idx = %d, s[i] = %d, temp = %s \n",idx,s[i],temp);
                //strcat(s,temp);
                count+=idx;
            }
        }
    }

    printf("s = %s\n",s);
    return s;

}


int main(){

    int a = 2;
    char *str;

    str = countAndSay(a);

    printf("str = %s\n",str);
    return 0;
}
