# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-28 19:41:37
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-28 19:56:20

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(l1, l2):

	result_linkNode = ListNode()
	prevhead = result_linkNode

	while l1 and l2:

		if l1.val < l2.val:
			prevhead.next = l1
			l1 = l1.next
		else:
			prevhead.next = l2
			l2 = l2.next

		prevhead = prevhead.next


	if l1:
		prevhead.next = l1
	else:
		prevhead.next = l2

	return result_linkNode.next

if __name__ == '__main__':
	l1_items = [1,2,4]
	l2_items = [1,3,4]

	l1 = temp_l1 = ListNode()
	l2 = temp_l2 = ListNode()	

	for i in range(len(l1_items)):
		l1.val = l1_items[i]
		if i != len(l1_items) - 1:
			l1.next = ListNode()
			l1 = l1.next

	for j in range(len(l2_items)):
		l2.val = l2_items[j]
		if j != len(l1_items) - 1:
			l2.next = ListNode()
			l2 = l2.next

	res = mergeTwoLists(temp_l1,temp_l2)

	while res:
		print(res.val)
		res = res.next


