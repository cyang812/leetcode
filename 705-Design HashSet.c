/*
* @Author: cyang
* @Date:   2018-09-29 11:51:56
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 13:06:38
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int max;
	int cnt;
    int hastset[10000];
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
	MyHashSet *hastset = NULL;

	hastset = (MyHashSet *)malloc(sizeof(MyHashSet));
	if (hastset)
	{
		hastset->max = 0;
		hastset->cnt = 0;
		memset(hastset->hastset, 0, sizeof(int) * 10000);
	}

	return hastset;
}

void myHashSetAdd(MyHashSet* obj, int key) {
	int count = obj->max;

    for (int i = 0; i < count; ++i)
    {
    	if(key == obj->hastset[i])
    		return;
    }

    obj->hastset[count] = key;
    obj->cnt++;
    obj->max++;
}

void myHashSetRemove(MyHashSet* obj, int key) {
	int count = obj->max;

    for (int i = 0; i < count; ++i)
    {
    	if(key == obj->hastset[i])
    	{
    		obj->hastset[i] = 0;
    		break;
    	}
    }
    obj->cnt--;	    
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int count = obj->max;

    for (int i = 0; i < count; ++i)
    {
    	if(key == obj->hastset[i])
    		return true;
    }

    return false;
}

void myHashSetFree(MyHashSet* obj) {
    if (obj)
    {
    	free(obj);
    }
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * struct MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */

int main(int argc, char const *argv[])
{
	MyHashSet *HashSet = NULL;
	HashSet = myHashSetCreate();

	if(HashSet == NULL)
	{
		printf("create HashSet err\n");
		return 0;
	}

	myHashSetAdd(HashSet, 1);
	myHashSetAdd(HashSet, 2);

	printf("%d \n", myHashSetContains(HashSet, 1));
	printf("%d \n", myHashSetContains(HashSet, 3));

	myHashSetAdd(HashSet, 2);	
	printf("%d \n", myHashSetContains(HashSet, 2));

	myHashSetRemove(HashSet, 2);
	printf("%d \n", myHashSetContains(HashSet, 2));

	myHashSetFree(HashSet);

	return 0;
}