<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-08 15:20:44
 * @LastEditTime: 2019-09-08 15:55:03
 * @Description: 300. Longest Increasing Subsequence
 -->

## 题目

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
```
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
```

Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

## 题解

### 动态规划 O(n^2)

1. 用一个一维空间f[i]来表示第i个元素为止时，从0到i之间的最长上升子序列的元素个数，如f[5] = 3就表示从第0个到第5个元素之间存在的最长的上升子序列长度为3；
2. f[i]的状态是从前面f[j] (其中j = 0, 1, ... , i-1) 的状态转移过来的，转移分两种情况：
    - 如果 nums[i] > nums[j], 说明第i个元素可以放在第j个元素后面作为一个新的上升子序列，f[i]的状态更新为f[j]+1；
    - 如果 nums[i] <= nums[j],说明第i个元素不满足在第j个元素后构成上升子序列的要求，此时状态维持不变，f[i]初始化为1（上升子序列最小长度为1）;
3. 根据上述推导出状态转移方程为 当nums[i] > nums[j]时，f[i] = max(f[i], f[j] + 1) j = 0, 1, ... i-1;
4. f中的状态更新完毕后，f中会保存从以每个元素结尾的最长上升子序列的长度，遍历一遍f返回其中的最大值即可求出整个序列的最长上升子序列长。


### 二分查找 O(nlogn)
