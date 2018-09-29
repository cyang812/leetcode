/*
* 242. Valid Anagram
* two solutions 
* isAnagram2 is faster
*/

#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {

	int a[26]={0};

	if(s==NULL && t==NULL)
		return true;
	if(strlen(s) != strlen(t))
		return false;

	for(int i=0; i<strlen(s); i++)
	{
		a[s[i]-'a']++;
		a[t[i]-'a']--;
	}

	for(int j=0; j<26; j++)
	{
		if(a[j] != 0)
		{
			printf("a[%d] = %d\n",j,a[j]);	
			return false;
		}
	}

	return true;
}

bool isAnagram2(char* s, char* t)
{
    int c[256]={0};
    //for (int i = 0; i < 256; i++) { c[i] = 0; }
    while (*s != '\0') { c[*s++]++; }
    while (*t != '\0') { c[*t++]--; }
    for (int i = 0; i < 256; i++) {
        if (c[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
	bool res;

	char s1[] = "abcsdd";
	char s2[] = "bcdda";

	res = isAnagram2(s1,s2);
	printf("res = %d\n", res);

	return 0;
}