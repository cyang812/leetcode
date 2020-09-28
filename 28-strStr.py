# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-28 19:57:11
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-28 19:58:45

def strStr(haystack, needle):

	len_1 = len(haystack)
	len_2 = len(needle)

	if len_2 == 0 or haystack == needle:
		return 0
	if len_1 < len_2:
		return -1
	
	# print(len_1, len_2, len_1-len_2)
	for idx in range(len_1-len_2+1):

		temp = haystack[idx:idx+len_2]
		# print(idx, temp)

		if temp == needle:
			return idx 

	return -1

if __name__ == '__main__':
	haystack = 'hello'
	needle = 'll'

	res = strStr(haystack, needle)

	print(res)