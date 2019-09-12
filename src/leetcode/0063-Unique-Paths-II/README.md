<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 14:33:53
 * @LastEditTime: 2019-09-12 14:42:47
 * @Description: 63. Unique Paths II
 -->

## 题目

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
```
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

## 题解

### 动态规划 O(n^2)

1. 用一个二维数组f[i][j]表示从起点(0, 0)到(i, j)的路径数量；
2. 因为机器人只能往右或者往下走，所以f[i][j]的状态只可能有两个来源：
    
    - 来自左方的f[i][j-1];
    - 来自右边的f[i-1][j];

3. 由此可推出状态转移方程为：f[i][j] = f[i][j-1] + f[i-1][j];
4. 循环迭代更新状态，最后输出终点的状态f[n-1][m-1]即可。

注： 需要注意上边界和左边界的条件判断，还有如果当前位置有障碍物就不更新当前位置的状态。
