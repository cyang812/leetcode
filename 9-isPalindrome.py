# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-22 19:45:30
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-22 19:46:38



def isPalindrome(x):

    if x < 0:
        return False

    strX = str(x)
    strY = list(strX)
    length = len(strX)
    
    for idx in range(length):
        strY[idx] = strX[length - idx - 1]
        
    strY = ''.join(strY)
    if strX == strY:
        return True
    else:
        return False

if __name__ == '__main__':
     result = isPalindrome(131)
     print(result)