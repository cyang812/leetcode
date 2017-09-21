#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>

bool strContains(const char *s, const char *t)
{
	int c1[256]={0};
	int c2[256]={0};

    while (*s != '\0') { c1[*s++]++; }
    while (*t != '\0') { c2[*t++]++; }

    for (int i = 0; i < 256; i++) {
        if (c1[i] < c2[i])
        {
            //printf("c1[%d] = %d, c2[%d] = %d\n",i,c1[i],i,c2[i]);
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t)
{
	int t_len = strlen(t);
	int s_len = strlen(s);
	int loop_cnt = s_len-t_len+1;
	char temp[s_len+1];
	int temp_len = 0;
	int res_len = s_len;
	static char res[50] = {0};
	const char *p_s = s;

	if(s_len<t_len)
	{
		return res;
	}

	for(int i=0; i<loop_cnt; i++)
	{
		for(int j=0; j<(s_len-t_len-i+1); j++)
		{
			temp_len = s_len-i-j;
			strncpy(temp,p_s,temp_len);
			temp[temp_len]='\0';
			printf("temp = %s\n",temp);

			if(strContains(temp,t))
			{
				//printf("temp_len = %d, res_len = %d\n",temp_len,res_len);
				if(temp_len <= res_len)
				{
					res_len = temp_len;
					strcpy(res,temp);
				}
			}
		}
		p_s++;
	}

	printf("res_len = %d\n", res_len);
	return res;
}

int main(int argc, char const *argv[])
{
	// char s[] = "ADOBECODEBANC";
	// char t[] = "ABC";
	char s[] = "a";
	char t[] = "aa";
	char *res;

	res = minWindow(s,t);
	printf("res = %s\n", res);

	//system("pause");
	return 0;
}
