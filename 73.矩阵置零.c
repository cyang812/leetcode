

/*
 * @Author: AIPC cy950812@gmail.com
 * @Date: 2025-02-28 09:57:25
 * @LastEditors: AIPC cy950812@gmail.com
 * @LastEditTime: 2025-02-28 10:24:41
 * @FilePath: _leetcode_73.矩阵置零.c
 * @Description:
 *
 * Copyright (c) 2025 by AIPC, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>

#define countof(x)  (sizeof(x) / sizeof(x[0]))

void brushRow(int** matrix, int m, int matrixColSize)
{
    for (int i = 0; i < matrixColSize; i++)
    {
        matrix[m][i] = 0;
    }
}

void brushColumn(int** matrix, int n, int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i][n] = 0;
    }
}

int contains(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
            return 1;
    }

    return 0;
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    int *row = (int *)malloc(sizeof(int) * matrixSize);
    int *column = (int *)malloc(sizeof(int) * matrixColSize[0]);
    int rowCnt = 0;
    int columnCnt = 0;

    // find all zero
    for (int m = 0; m < matrixSize; m++)
    {
        for (int n = 0; n < matrixColSize[0]; n++)
        {
            if (matrix[m][n] == 0)
            {
                if (!contains(row, rowCnt, m))
                {
                    row[rowCnt++] = m;
                }

                if (!contains(column, columnCnt, n))
                {
                    column[columnCnt++] = n;
                }
            }
        }
    }

    for (int m = 0; m < matrixSize; m++)
    {
        if (contains(row, rowCnt, m))
        {
            brushRow(matrix, m, matrixColSize[0]);
        }
    }

    for (int n = 0; n < matrixColSize[0]; n++)
    {
        if (contains(column, matrixColSize[0], n))
        {
            brushColumn(matrix, n, matrixSize);
        }
    }

    // printf("print result:\n");
    // for (int m = 0; m < matrixSize; m++)
    // {
    //     for (int n = 0; n < matrixColSize[m]; n++)
    //     {
    //         printf("%d, ", matrix[m][n]);
    //     }
    //     printf("\n");
    // }
}

// void main()
// {
//     // int row1[] = {1, 1, 1};
//     // int row2[] = {1, 0, 1};
//     // int row3[] = {1, 1, 1};

//     // int row1[] = {0, 1, 2, 0};
//     // int row2[] = {3, 4, 5, 2};
//     // int row3[] = {1, 3, 1, 5};

//     // int *matrix[] = {row1, row2, row3};
//     // int matrixColSize[] = {countof(row1), countof(row2), countof(row3)};

//     int row1[] = {0, 0, 0, 5};
//     int row2[] = {4, 3, 1, 4};
//     int row3[] = {0, 1, 1, 4};
//     int row4[] = {1, 2, 1, 3};
//     int row5[] = {0, 0, 1, 1};

//     int *matrix[] = {row1, row2, row3, row4, row5};
//     int matrixColSize[] = {countof(row1), countof(row2), countof(row3), countof(row4), countof(row5)};
//     printf("countof(matrix): %d\n", countof(matrix));

//     setZeroes(matrix, countof(matrix), matrixColSize);
// }
// @lc code=end

