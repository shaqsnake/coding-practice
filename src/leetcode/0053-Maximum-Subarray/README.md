<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-04 16:33:10
 * @LastEditTime: 2019-09-06 15:59:03
 * @Description: 53. Maximum Subarray
 -->

## 题目

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## 题解

### 递推 O(n)

1. 将返回值res设为最小值后，开始遍历整个数组；
2. 依次把每个数累加到变量sum上，更新sum时将sum值与当前数做比较，取较大值更新sum；
3. 同样将sum值与当前res值比较，用较大值更新res；
4. 完成遍历后返回res。

### 动态规划 O(n)

1. 用一维数组 f 表示状态集合，其中 f(i) 表示第i个元素为止前面i个元素的最大连续元素和；
2. 分析f[i]状态的两种情况：
    - 如果f[i]包括nums[i]之前的连续元素，那 f[i] = f[i-1] + nums[i] 
    - 如果f[i]不包括nums[i]之前的元素，那f[i]只可能包含nums[i]一个元素，所以 f[i] = nums[i]
3. 根据以上分析，推导出状态转移方程： f[i] = max(f[i-1], 0) + nums[i];
4. 最后遍历f, 求出最大值。

注：因为f[i]的状态转移只和f[i-1]相关，所以可以优化代码到O(1)的空间复杂度，最后代码类似递推的实现。