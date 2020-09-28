# -*- coding: utf-8 -*-
# @Author: cyang
# @Date:   2020-09-25 19:51:28
# @Last Modified by:   cyang
# @Last Modified time: 2020-09-26 09:35:22

import time
import matplotlib.pyplot as plt
import numpy as np

loop_1_list = list()
loop_2_list = list()

def divide(dividend, divisor):

	if (dividend > 0 and divisor > 0) or (dividend <0 and divisor < 0):
		flag = 1    
	else:
		flag = 0    
	
	if abs(dividend) < abs(divisor):
		return 0
	elif abs(dividend) == abs(divisor):
		return 1 if flag else -1

	# if abs(divisor) == 1:
	# 	if dividend == -2147483648 and divisor == -1: 
	# 		return 2147483648-1
	# 	else:
	# 		return abs(dividend) if flag else -abs(dividend)    

	dividend = abs(dividend)
	divisor = abs(divisor)
	
	result = 0
	loop_1 = 0
	loop_2 = 0

	while dividend >= divisor:
		loop_1 += 1
		temp_divisor, count = divisor, 1
		while dividend >= temp_divisor:
			loop_2 += 1
			dividend -= temp_divisor
			result += count
			count <<= 1
			temp_divisor <<= 1

	loop_1_list.append(loop_1)
	loop_2_list.append(loop_2)

	if flag:
		return result, loop_1, loop_2
	else:
		return -result, loop_1, loop_2



if __name__ == '__main__':
	dividend = 2147483647
	divisor = 0
	loop_cnt = 100

	for divisor in range(1, loop_cnt):
		toc = time.time()
		result = divide(dividend, divisor)
		tic = time.time()
		print(result, (tic-toc)*1000)

	x = np.arange(1, loop_cnt, 1)
	plt.plot(x, loop_1_list)
	plt.plot(x, loop_2_list)
	plt.show()	

