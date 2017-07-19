/*
* 557. Reverse Words in a String III
* note: �������ⷨ���������ַ�������ʱ������ͨ��
*       �������ϵ������ⷨ
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// �������һ������
char* reverseAWord(char *s)
{
	int length=0;
	int i=0;
	//static char temp[10];
	char *temp = (char *)malloc(200*sizeof(char));

	//while(*s++)length++; //ע�⣺���ַ�ʽ����ȡ�ַ������ȣ���ı�sָ��λ��
	length = strlen(s);
	printf("length:%d\n",length);
    //printf("raw Str: %s\n",s);

	for(i; i<length; i++)
	{
		temp[i] = s[length-i-1];
		printf("temp[%d] = %c\n",i,temp[i]);
	}
	temp[i] = '\0';

	printf("ret str : %s \n",temp);
	return temp;
}
#if 0
// �����ӷֽ�ɵ���
char* reverseWords(char* s) {

    int index = 1,i=0,j=0,y;
    static int x = 0;
    int idx,count=0;//count��ʾ�����пո�ĸ���
    int space[10] = {0};
    static char tempStr1[10],tempStr2[10];
    static char resStr[100];
    char *strPtr = s;
    char *resStrPtr = resStr;
    char *tempStr2Ptr = tempStr2;

    printf("raw str = %s\n",s);

    //�ҵ��ո񲢼�¼��������
    while(*s++ != '\0')
    {
        index++;
        if(*s == ' ')
        {
            space[++i] = index;
            count++;
            printf("get value\n");
        }
    }
    space[++count] = strlen(strPtr)+1;

    #if 0
    //for test
    for(j = 0; j<10; j++)
   // while(space[j+1] != 0)
    {
    //    j++;
        printf("space[%d] = %d\n",j,space[j]);
    }
    #endif

    //���ݿո�ֽⵥ��
    i = 0;
    j = 0;
    //count+=1;// ��һ��ʾ��������
    //while(space[i+1] != 0)
    while(count--)
    {
        printf("count-- = %d\n",count);
        //�ֽ�ɵ���
        for(j=0; j<(space[i+1]-space[i]-1); j++)
        {
            idx = j+space[i];
            //printf("s[%d] = %c\n",idx,strPtr[idx]);
            tempStr1[j] = strPtr[idx];
            printf("tempStr1[%d] = %c\n",j,tempStr1[j]);
        }
        tempStr1[j] = '\0';
        i++;
        printf("tempStr1 = %s\n",tempStr1);

        //����һ������
        tempStr2Ptr = reverseAWord(tempStr1);
        //strcat(resStr,tempStr2);
        //strcat(resStr,' ');

        //��������ĵ���Ϊһ������
        for(x,y=0; y<strlen(tempStr2Ptr); x++,y++)
        {
            resStr[x] = tempStr2Ptr[y];
        }
        if(count != 0)
            resStr[x++] = ' ';

    }
    printf("resStr = %s\n",resStr);
	return resStr;
}
#endif

// ����һ���ַ���
void reverse(int b, int e, char *s){
    while(b < e) {
        s[b] = s[b] ^ s[e];
        s[e] = s[b] ^ s[e];
        s[b] = s[b] ^ s[e];
        b++;
        e--;
    }
}

// �ֽ���ӳɵ��ʺ����������
char* reverseWords(char* s) {
    int i, s_len = strlen(s), index = 0;

    for(i = 0; i <= s_len; i++) {
        if((s[i] == ' ') || (s[i] == '\0')){  // �����ֿո���߽���ʱ������������
            reverse(index, i - 1, s);
            index = i + 1; // ����ָ��
        }
    }
    return s;
}

int main()
{
	//char rawStr[] = "let's take LeetCode contest";
	char rawStr[] = "hello";
	char aWord[] = "let's";
	char *ptr;

	//char resStr[50] = {0},*ptr;
	//ptr = resStr;

	//ptr = reverseAWord(aWord);
	ptr = reverseWords(rawStr);

	printf("raw str len=%d, str len=%d\n",strlen(rawStr),strlen(ptr));
	printf("res str:%s\n",ptr);

    return 0;
}
