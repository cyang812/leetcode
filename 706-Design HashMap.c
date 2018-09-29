/*
* @Author: cyang
* @Date:   2018-09-29 13:07:43
* @Last Modified by:   cyang
* @Last Modified time: 2018-09-29 13:37:10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max;
    int cnt;
    int key[10000];
    int val[10000];
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap *myHashMap = NULL;

    myHashMap = (MyHashMap *)malloc(sizeof(MyHashMap));

    if (myHashMap)
    {
    	myHashMap->max = 0;
    	myHashMap->cnt = 0;
    	memset(myHashMap->key, 0, sizeof(int) * 10000);
    	memset(myHashMap->val, 0, sizeof(int) * 10000);
    }

    return myHashMap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int cnt = obj->max;

    for (int i = 0; i < cnt; ++i)
    {
    	if (key == obj->key[i])
    	{
    		obj->val[i] = value;
    		return;
    	}
    }

    obj->key[cnt] = key;
    obj->val[cnt] = value;
    obj->cnt++;
    obj->max++;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
	int cnt = obj->max;

	for (int i = 0; i < cnt; ++i)
    {
    	if (key == obj->key[i])
    	{
    		return obj->val[i];
    	}
    }

    return -1;    
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int cnt = obj->max;

    for (int i = 0; i < cnt; ++i)
	{
		if (key == obj->key[i])
		{
			obj->key[i] = 0;
			obj->val[i] = 0;
			break;
		}
	}	

	obj->cnt--;
}

void myHashMapFree(MyHashMap* obj) {
    if (obj)
    {
    	free(obj);
    }
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * struct MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 * int param_2 = myHashMapGet(obj, key);
 * myHashMapRemove(obj, key);
 * myHashMapFree(obj);
 */

int main(int argc, char const *argv[])
{
	MyHashMap *myHashMap = NULL;

	myHashMap = myHashMapCreate();
	if (myHashMap == NULL)
	{
		printf("create hashmap err\n");
		return 0;
	}

	myHashMapPut(myHashMap, 1, 1);
	myHashMapPut(myHashMap, 2, 2);

	printf("%d\n", myHashMapGet(myHashMap, 1));
	printf("%d\n", myHashMapGet(myHashMap, 3));

	myHashMapPut(myHashMap, 2, 1);	
	printf("%d\n", myHashMapGet(myHashMap, 2));	

	myHashMapPut(myHashMap, 2, 5);	
	printf("%d\n", myHashMapGet(myHashMap, 2));	

	myHashMapRemove(myHashMap, 2);
	printf("%d\n", myHashMapGet(myHashMap, 2));		

	myHashMapFree(myHashMap);

	return 0;
}