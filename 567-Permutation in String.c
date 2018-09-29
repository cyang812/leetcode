/*
* 567. Permutation in String
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
			//printf("a[%d] = %d\n",j,a[j]);	
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

bool checkInclusion(char* s1, char* s2)
{
	int s1_len = strlen(s1);
	int loop_cnt = strlen(s2)-s1_len+1;
	char temp[s1_len+1];
	const char *p_s2 = s2;
	int idx = 0;
	
	printf("s1_len = %d , loop_cnt = %d\n",s1_len,loop_cnt);
	for(int i=0; i<loop_cnt; i++)
	{
		strncpy(temp,p_s2,s1_len);
		temp[s1_len]='\0';
		p_s2++;
		//printf("temp = %s\n",temp);
		
		if(isAnagram2(temp,s1))
		{
			return true;
		}
	}    

	return false;
}

int main(int argc, char const *argv[])
{
	
	char s[] = "st";
	char p[] = "abeasd";
	bool res;

	res = checkInclusion(s,p);

	printf("res = %d\n", res);

	return 0;
}