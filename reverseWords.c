#include <stdio.h>
#include <stdint.h>

// 倒序输出一个单词
char* reverseAWord(char *s)
{
	int length=0;
	int i=0;
	static char temp[20];

	while(*s++)length++;
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
#if 1
// 将句子分解成单词
char* reverseWords(char* s) {

    int index = 0;
    char tempStr[10];
    static char resStr[100];

    while(*s++!='\0' && *s== ' ')
    {
        temp[index++] = *s++;

        reverseAWord(temp);
    }

	return resStr;
}
#endif
int main()
{
	char rawStr[] = "let's take LeetCode contest";
	char aWord[] = "let's";
	char *ptr;

	//char resStr[50] = {0},*ptr;
	//ptr = resStr;

	//ptr = reverseWords(rawStr);
	ptr = reverseAWord(aWord);

	printf("ptr:%s\n",ptr);

	return 0;
}
