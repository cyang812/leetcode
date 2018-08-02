/*
*2. Add Two Numbers
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *p1 = l1;
   	struct ListNode *p2 = l2;

	struct ListNode *ret_list = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p_ret = 0;
    ret_list->val = 0;

    int carry = 0;
    int x,y,z;

    while(p1 || p2 || carry)
    {
    	if (p_ret == 0)
    	{
    		/* code */
    		p_ret = ret_list;
    	}
    	else
    	{
    		p_ret->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    		p_ret = p_ret->next;
    		p_ret->val = 0;
    	}
    	
    	x = p1 == 0? 0:p1->val;
    	y = p2 == 0? 0:p2->val;
    	z = x+y+carry;

    	carry = z/10;
    	p_ret->val = z%10;
    	p_ret->next = 0;

    	p1 = p1 == 0? 0:p1->next;
    	p2 = p2 == 0? 0:p2->next;
    }

    return ret_list;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a[] = {2,4,3};
	int b[] = {5,6,4};

	struct ListNode *p1 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	struct ListNode *p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p1->val = a[0];
	p2->val = b[0];

	struct ListNode *l1 = p1;
	struct ListNode *l2 = p2;

	struct ListNode *retVal,*p_ret;

	for (int i = 1; i < 3; i++)
	{
		p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p1 = p1->next;
		p1->val = a[i];

		p2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p2 = p2->next;
		p2->val = b[i];
	}

	p1->next = NULL; p2->next = NULL;

	retVal = addTwoNumbers(l1,l2);
	p_ret = retVal;

	while(p_ret)
	{
		printf("%d ", p_ret->val);
		p_ret = p_ret->next;
	}

	if (retVal)
	{
		/* code */
		free(retVal);
	}
	if (l1)
	{
		/* code */
		free(l1);
	}
	if (l2)
	{
		/* code */
		free(l2);
	}

	return 0;
}