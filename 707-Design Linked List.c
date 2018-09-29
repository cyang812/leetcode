/*
* @Author: cyang
* @Date:   2018-09-29 13:38:46
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 16:39:45
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    void *next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *mylist = NULL;
    mylist = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    if (mylist)
    {
    	mylist->val = -1;
    	mylist->next = NULL;
    }

    return mylist;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
	MyLinkedList *list = obj;
	int cnt = index;

	while(cnt--)
	{
		if (list->next)
		{
			list = (MyLinkedList *)list->next;
		}
		else
			return -1;
	}

	return list->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	//head	
	if (obj->val == -1)
	{
		obj->val = val;
		return;
	}

	MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(list)
	{
		list->val = obj->val;
		list->next = obj->next;
	}

	obj->val = val;
	obj->next = list;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	//head
	if (obj->val == -1)
	{
		obj->val = val;
		return;
	}

 	MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
 	MyLinkedList *temp = obj;

	if(list)
	{
		while(temp->next)
		{
			temp = (MyLinkedList *)temp->next;
		}

		temp->next = list;
		list->val = val;
		list->next = NULL;
	}   
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if (index == 0)
	{
		myLinkedListAddAtHead(obj, val);
		return;
	}
	else
	{
		if (obj->val == -1)
		{
			return;
		}
	}

    MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
 	MyLinkedList *temp = obj;  
 	MyLinkedList *next = (MyLinkedList *)temp->next;

	int cnt = index - 1;

	while(cnt--)
	{
		if (next->next)
		{
			temp = (MyLinkedList *)temp->next;
			next = (MyLinkedList *)temp->next;
		}
		else if (temp->next)
		{
			//tail
			temp = (MyLinkedList *)temp->next;
			temp->next = list;
			list->val = val;
			list->next = NULL;
			return;
		}
		else
			return;
	}

	temp->next = list;
	list->next = next;
	list->val = val;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
 	MyLinkedList *temp = obj;  
 	MyLinkedList *next = (MyLinkedList *)temp->next;

 	void *temp_addr = NULL;
	int cnt = index - 1;

	if(index == 0)
	{
		//head
		temp = (MyLinkedList *)obj->next;
		obj->val = temp->val;
		obj->next = (MyLinkedList *)temp->next;
		free(temp);		
		return;
	}

	while(cnt--)
	{
		if (next->next)
		{
			temp = (MyLinkedList *)temp->next;
			next = (MyLinkedList *)temp->next;
		}
		else if (temp->next)
		{
			//tail
			temp = (MyLinkedList *)temp->next;
			next = temp;
		}
		else
			return;
	}

	temp_addr = next;
	temp->next = (MyLinkedList *)next->next;
	free(temp_addr);
}

void myLinkedListFree(MyLinkedList* obj) {
	void *temp_addr = NULL;

    while (obj)
    {
    	printf("delete obj->val = %d\n", obj->val);
    	temp_addr = obj;	
    	obj = (MyLinkedList *)obj->next;
    	free(temp_addr);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main(int argc, char const *argv[])
{
	MyLinkedList *linkList = (MyLinkedList *)myLinkedListCreate();

	if (linkList == NULL)
	{
		printf("create linkList err\n");
		return 0;
	}
	#if 0
	myLinkedListAddAtHead(linkList, 1);
	myLinkedListAddAtIndex(linkList, 0, 10);
	myLinkedListAddAtHead(linkList, 2);
	myLinkedListAddAtHead(linkList, 3);
	myLinkedListAddAtHead(linkList, 4);
	myLinkedListAddAtHead(linkList, 5);	
	myLinkedListAddAtTail(linkList, 4);

	myLinkedListDeleteAtIndex(linkList, 5);

	printf("idx%d = %d\n", 0, myLinkedListGet(linkList, 0));
	printf("idx%d = %d\n", 1, myLinkedListGet(linkList, 1));
	printf("idx%d = %d\n", 2, myLinkedListGet(linkList, 2));
	printf("idx%d = %d\n", 3, myLinkedListGet(linkList, 3));
	printf("idx%d = %d\n", 4, myLinkedListGet(linkList, 4));
	printf("idx%d = %d\n", 5, myLinkedListGet(linkList, 5));
	printf("idx%d = %d\n", 6, myLinkedListGet(linkList, 6));
	printf("idx%d = %d\n", 7, myLinkedListGet(linkList, 7));
	#else

	printf("idx%d = %d\n", 0, myLinkedListGet(linkList, 0));

	myLinkedListAddAtIndex(linkList, 1, 2);
	printf("idx%d = %d\n", 0, myLinkedListGet(linkList, 0));	
	printf("idx%d = %d\n", 1, myLinkedListGet(linkList, 1));

	myLinkedListAddAtIndex(linkList, 0, 1);
	printf("idx%d = %d\n", 0, myLinkedListGet(linkList, 0));	
	printf("idx%d = %d\n", 1, myLinkedListGet(linkList, 1));

	#endif

	myLinkedListFree(linkList);

	return 0;
}