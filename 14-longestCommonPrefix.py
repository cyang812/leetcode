# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-22 19:47:03
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-22 19:48:39

def longestCommonPrefix(strs):
    if len(strs) == 0:
        return ''

    temp = list()
    str1 = strs[0]
    for idx in range(1, len(strs)):            
        temp = list()
        for i in range(min(len(str1), len(strs[idx]))):
            if str1[i] == strs[idx][i]:
                temp.append(str1[i])
            else:
                break

        str1 = ''.join(temp)
    
    temp = list(str1)
    result = ''.join(temp)
    return result  

if __name__ == '__main__':
	str_list = ['aca', 'cba']
	result = longestCommonPrefix(str_list)
	print(result)
