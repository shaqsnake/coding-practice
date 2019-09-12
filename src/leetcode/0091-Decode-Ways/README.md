<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 15:25:27
 * @LastEditTime: 2019-09-12 15:33:48
 * @Description: 91. Decode Ways
 -->

## 题目

A message containing letters from A-Z is being encoded to numbers using the following mapping:
```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
```
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```

Example 2:
```
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

## 题解

### 动态规划 0(n)

1. 用一维数组f[i]表示到第i个字符时的解码方案数；
2. f[i]状态可划分为：

    - 第i个字符s[i]可解码时(s[i] != '0')的方案数；
    - 第i-1个和第i个字符 s[i-1]s[i] 可解码时(10 <= s[i-1]s[i] <= 26)的方案数；

3. 推出状态转移方程为 f[i] = f[i-1] + f[i-2];
4. 最后输出最后一个字符对应的状态值f[n]即可。
