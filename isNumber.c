/*
*65. Valid Number
*/

#include <stdio.h>
#include <stdbool.h>

/*
* flag:
	1 - + -
	2 - 0~9
	3 - .
	4 - space
	5 - e
* cnt: the count of numbers
*/

bool isNumber(char* s) {

    bool retVal = true;
    
	int tmp = 0;
	int flag = 0;
	int err = 0;
	int cnt = 0;

	while(*s && err==0)
	{
		tmp = *s - '0';	

		if(flag == 0)
		{		
			if(*s == ' ')
			{

			}
			else if(*s == '+' || *s == '-')
			{
				flag = 1;
			}
			else if(tmp <= 9 && tmp >= 0)
			{
				cnt++;
				flag = 2;
			}
			else if(*s == '.')
			{
				flag = 3;
			}
			else
			{
				err = 1;
			}
		}
		else
		{
			if(tmp <= 9 && tmp >= 0)
			{
				if(flag == 4)
					err = 1;
				cnt++;
			}
			else if( (*s == '.' && flag == 3) || (*s == '.' && flag == 4) || (*s == '.' && flag == 5) )
			{
				err = 1;
			}
			else if( *s == 'e' && cnt == 0 )
			{
				err = 1;
			}
			else if( (*s == 'e' && flag == 4) || (*s == 'e' && flag == 5) )
			{
				err = 1;
			}
			else if( (*s == '+' && flag == 5) || (*s == '-' && flag == 5) )
			{
				if(cnt != 0)
					err = 1;
			}
			else if(*s == '.')
			{
				flag = 3;
			} 
			else if(*s == ' ')
			{
				flag = 4;
			}	
			else if(*s == 'e')
			{
				cnt = 0;
				flag = 5;
			}
			else
			{
				err = 1;
			}
		}

		s++;
	}

	printf("flag = %d\n", flag);
	printf("err = %d\n", err);
	printf("cnt = %d\n", cnt);

	if(err || cnt==0)
		retVal = false;

	return retVal;
}

int main(int argc, char const *argv[])
{
	/* code */
	char str1[] = "0.1";    //true 
	char str2[] = "abc";	//false
	char str3[] = " ";      //false
	char str4[] = "1  ";    //true
	char str5[] = ".1";     //true
	char str6[] = "2e0";    //true
	char str7[] = "0e";     //false
	char str8[] = "..2";    //false
	char str9[] = "3.";     //true
	char str10[] = ".  1";  //false
	char str11[] = "1 1";   //false
	char str12[] = ".e1";   //false
	char str13[] = "0..";   //false
	char str14[] = "3. ";   //true
	char str15[] = "1 .";   //false
	char str16[] = "46.e3"; //true
	char str17[] = "6e6.5"; //false
	char str18[] = "6ee69"; //false
	char str19[] = "96 e5"; //false
	char str20[] = "-e58";  //false
	char str21[] = " 005047e+6"; //true
	char str22[] = "459277e38+"; //false
	char str23[] = ".1.";   //false

	printf("str22 : %d\n", isNumber(str22));

	return 0;
}