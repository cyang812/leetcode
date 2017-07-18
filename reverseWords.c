#include <stdio.h>
#include <stdint.h>

char* reverseAWord(char *s)
{
	int length=0;
	int i=0;
	char temp[20],*ptr;
    ptr = temp;

	while(*s++)length++;
	printf("length:%d\n",length);

	for(i; i<length; i++)
	{
		temp[i] = s[length-i-1];
		//printf("temp[%d] = %c\n",i,temp[i]);
	}
	temp[i] = '\0';

	printf("ret str : %s \n",*temp);
	return ptr;
}
#if 0
char* reverseWords(char* s) {

	char tempStr[20] = "asd";
	char resStr[50] = "asd";
	int i = 0,j = 0,index = 0;
	int resStrIdx;

	printf("entry fun\n");

	for(i; s[i]!='\0'; i++)
	{
		//get a word
		for(j=i; s[j]!=' '; j++)
		{
			tempStr[index++] = s[j];
		}

		// change ptr to the next word
		i = j+1;

		//reverse a word
		for(j=0; j<index; j++)
		{
			tempStr[j] = s[index-j];
		}

		//add to a sum str
		for(resStrIdx=0; resStrIdx<index; resStrIdx++)
		{
			resStr[resStrIdx] = tempStr[resStrIdx];
		}

		//clear
		index = 0;
	}

	return resStr;
}
#endif
int main()
{
	char *rawStr = "let's take LeetCode contest";
	char *aWord = "hello";
	char *ptr;

	//char resStr[50] = {0},*ptr;
	//ptr = resStr;

	//ptr = reverseWords(rawStr);
	ptr = reverseAWord(aWord);

	printf("%s\n",ptr);

	return 0;
}
