<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-04 16:33:10
 * @LastEditTime: 2019-09-04 16:48:58
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
