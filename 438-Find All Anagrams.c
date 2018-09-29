/*
* 438. Find All Anagrams in a String
* isAnagram2 is faster than isAnagram.
* using isAnagram has time limit error
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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) 
{
	int p_len = strlen(p);
	int loop_cnt = strlen(s)-p_len+1;
	char temp[p_len+1];
	static int res[21000];
	const char *p_s = s;
	int idx = 0;
	
	for(int i=0; i<21000; i++)
	{
		res[i]=-1;
	}

	printf("p_len = %d , loop_cnt = %d\n",p_len,loop_cnt);
	for(int i=0; i<loop_cnt; i++)
	{
		strncpy(temp,p_s,p_len);
		temp[p_len]='\0';
		p_s++;
		//printf("temp = %s\n",temp);
		
		if(isAnagram2(temp,p))
		{
			res[idx] = i;
			idx++;
		}
	}    

	// for(int i=0; i<10; i++)
	// {
	// 	printf("res[%d] = %d ", i,res[i]);
	// }

	*returnSize = idx--;
	return res;
}

int main(int argc, char const *argv[])
{
	
	char s[] = "cbaeb";
	char p[] = "abe";
	int *res;
	int returnSize = 0;

	res = findAnagrams(s,p,&returnSize);
	printf("returnSize = %d\n",returnSize);
	for(int i=0; i<10; i++)
	{
		printf("res[%d] = %d ",i,res[i]);
		if(i!=0 && i%5==0)
		{
			printf("\n");
		}
	}

	return 0;
}