

/*
 * @Author: AIPC cy950812@gmail.com
 * @Date: 2025-02-27 08:58:39
 * @LastEditors: AIPC cy950812@gmail.com
 * @LastEditTime: 2025-02-27 08:59:23
 * @FilePath: _.leetcoded:_github_leetcode_41.缺失的第一个正数.c
 * @Description:
 *
 * Copyright (c) 2025 by AIPC, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstMissingPositive(int* nums, int numsSize) {

    //对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1,N+1] 中.
    int *temp = (int *)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0 && nums[i] <= numsSize)
        {
            temp[nums[i] - 1] = 1;
        }
    }

    // for (int i = 0; i < numsSize; i++)
    // {
    //     printf("%d, ", temp[i]);
    // }

    for (int i = 0; i < numsSize; i++)
    {
        if (temp[i] == 0)
            return i + 1;
    }

    return numsSize + 1;
}

void main()
{
    int nums[] = {7, 8, 9, 11, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = firstMissingPositive(nums, numsSize);
    printf("%d\n", result);
}
// @lc code=end

