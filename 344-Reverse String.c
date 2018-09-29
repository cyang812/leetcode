/*
* 344. Reverse String
* 541. Reverse String II
* 557. Reverse Words in a String III
* note: 不完美解法，当输入字符数过多时，不能通过
*       附带网上的完美解法
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define problem 1 // 2 3

// 倒序输出一个单词
char* reverseAWord(char *s)
{
	int length=0;
	int i=0;
	//static char temp[10];
	char *temp = (char *)malloc(200*sizeof(char));

	//while(*s++)length++; //注意：这种方式来获取字符串长度，会改变s指针位置
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
// 将句子分解成单词
char* reverseWords(char* s) {

    int index = 1,i=0,j=0,y;
    static int x = 0;
    int idx,count=0;//count表示句子中空格的个数
    int space[10] = {0};
    static char tempStr1[10],tempStr2[10];
    static char resStr[100];
    char *strPtr = s;
    char *resStrPtr = resStr;
    char *tempStr2Ptr = tempStr2;

    printf("raw str = %s\n",s);

    //找到空格并记录在数组中
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

    //根据空格分解单词
    i = 0;
    j = 0;
    //count+=1;// 加一表示单词数量
    //while(space[i+1] != 0)
    while(count--)
    {
        printf("count-- = %d\n",count);
        //分解成单词
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

        //逆序一个单词
        tempStr2Ptr = reverseAWord(tempStr1);
        //strcat(resStr,tempStr2);
        //strcat(resStr,' ');

        //组合逆序后的单词为一个句子
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

// 逆序一个字符串
void reverse(int b, int e, char *s){
    while(b < e) {
        s[b] = s[b] ^ s[e];
        s[e] = s[b] ^ s[e];
        s[b] = s[b] ^ s[e];
        b++;
        e--;
    }
}
#if(problem == 3)
// 分解句子成单词后调用逆序函数
char* reverseWords(char* s) {
    int i, s_len = strlen(s), index = 0;

    for(i = 0; i <= s_len; i++) {
        if((s[i] == ' ') || (s[i] == '\0')){  // 当出现空格或者结束时，调用逆序函数
            reverse(index, i - 1, s);
            index = i + 1; // 更改指针
        }
    }
    return s;
}
#elif(problem == 2)
char* reverseWords(char* s,int k) {

    int i = 0,j = 1,idx = 0;
    int len = strlen(s);
    int cnt = len/(2*k);
    int last = len%(2*k);

    printf("cnt = %d\n",cnt);
    printf("last = %d\n",last);

    for(i; i<cnt; i++)
    {
        reverse(idx,idx+k-1,s);
        idx+=2*k;
        printf("cnt\n");
        printf("s = %s\n",s);
    }
    if(last>=k){
        reverse(idx,idx+k-1,s);
        printf("if\n");
        printf("s = %s\n",s);
    }else{
        reverse(idx,idx+last-1,s);
        printf("else\n");
        printf("s = %s\n",s);
    }

    return s;
}
#elif(problem == 1)
char* reverseString(char* s) {
    int idx = 0;
    int len = strlen(s);

    reverse(idx,len-1,s);
    return s;
}
#endif
int main()
{
	//char rawStr[] = "let's take LeetCode contest";
	char rawStr[] = "hello";
	char aWord[] = "let's";
	char bWord[] = "abcdefgh";
	//char bWord[] = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
	char *ptr;
    int k = 3;

	//char resStr[50] = {0},*ptr;
	//ptr = resStr;

	//ptr = reverseAWord(aWord);
	//ptr = reverseWords(rawStr);
    //ptr = reverseWords(bWord,k);
    ptr = reverseString(bWord);

	printf("res str:%s\n",ptr);
	printf("raw str len=%d, str len=%d\n",strlen(bWord),strlen(ptr));

    return 0;
}
