/*
* 657. Judge Route Circle
*/

#include <stdio.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {

   	int upCnt = 0;
	int downCnt = 0;
	int rightCnt = 0;
	int leftCnt = 0;

	while(*moves)
	{
		switch(*moves)
		{
			case 'U':
				upCnt++;
				break;
			case 'D':
				downCnt++;
				break;
			case 'R':
				rightCnt++;
				break;
			case 'L':
				leftCnt++;
				break;
		}
		moves++;
	}

    printf("upCnt = %d , downCnt = %d \n",upCnt,downCnt);
	printf("rightCnt = %d , leftCnt = %d \n",rightCnt,leftCnt);

	if((upCnt == downCnt) && (rightCnt == leftCnt))
	{
		return true;
	}
	else
		return false;
}

int main()
{
    char *test_str = "RRLLDDUU";
    bool ret = false;

    ret = judgeCircle(test_str);
    printf("ret = %d\n",ret);
}
