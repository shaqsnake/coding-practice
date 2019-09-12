<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 16:46:57
 * @LastEditTime: 2019-09-12 17:01:02
 * @Description: 198. House Robber
 -->

## 题目

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
```
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```

Example 2:
```
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```

## 题解

### 动态规划 O(n)

1. 用两个一维数组f[i]和g[i]来表示状态，其中f[i]表示不选择第i个元素的方案数量，g[i]表示选择第i个元素的方案数量；
2. 状态转移可以分为两种情况：

    - f[i]的状态来源有两个，因为不选择第i个元素，所以第i-1个元素可选可不选，所以f[i]的状态应该为f[i-1]或g[i-1]之间的最大值；
    - g[i]的状态来源只有一种可能，因为选择了第i个元素，且不能选择相邻的元素，所以g[i]的状体应来源于f[i-1];

3. 由此可得状态转移方程为：

    - f[i] = max(f[i-1], g[i-1]);
    - g[i] = f[i-1] + nums[i];

4. 最后比较f[n]和g[n], 输出最大的方案数。
