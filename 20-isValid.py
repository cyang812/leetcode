# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-22 19:49:00
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-22 20:47:44


def isValid(s):
	c1 = s.count('(')
	c2 = s.count(')')
	c3 = s.count('[')
	c4 = s.count(']')
	c5 = s.count('{')
	c6 = s.count('}')

	print(c1, c2, c3, c4, c5, c6)

	if c1 != c2 or c3 != c4 or c5 != c6:
		return False

	stack = []
	size_1 = size_2 = size_3 = 0

	for idx in range(len(s)):
		temp = s[idx]
		if temp == '(' or temp == '[' or temp == '{':	
			if temp == '(':
				size_1 = size_1 + 1
				stack.append('(')
			elif temp == '[':
				size_2 = size_2 + 1
				stack.append('[')
			elif temp == '{':
				size_3 = size_3 + 1
				stack.append('{')
		elif len(stack):
			if temp == ')' and '(' == stack[len(stack) - 1]:
				size_1 = size_1 - 1
				del stack[len(stack) - 1]
			elif temp == ']' and '[' == stack[len(stack) - 1]:
				size_2 = size_2 - 1
				del stack[len(stack) - 1]
			elif temp == '}' and '{' == stack[len(stack) - 1]:
				size_3 = size_3 - 1      
				del stack[len(stack) - 1]               		
		else:
			return False		

	# if len(stack) == 0:
	# 	return True
	# else:
	# 	return False			

	# print(stack)		
	if size_1 == 0 and size_2 == 0 and size_3 == 0:
		return True
	else:
		return False

		
if __name__ == '__main__':
	testStr = "()"
	result = isValid(testStr)
	print(result)


