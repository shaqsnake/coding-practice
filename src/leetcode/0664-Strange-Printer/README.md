<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 14:55:57
 * @LastEditTime: 2019-09-16 15:25:43
 * @Description: 664. Strange Printer
 -->

## 题目

There is a strange printer with the following two special requirements:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:
```
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
```

Example 2:
```
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
Hint: Length of the given string will not exceed 100.
```

## 题解

### 动态规划 O(n^3)

1. 用一个二维数组f(l, r) 表示打印区间 [l, r] 所需要的最少步数。
2. 每次扩展到新的长度时，[l, r] 区间的首字符尤为重要，因为区间 [l, r] 的某个最优解一定是第一次将首字符全部写满区间 [l, r]，假设区间中最右侧仍保留着第一次写的首字符的位置为 k，状态更新分两种情况：

    - 若 k == l，则表示除了首字符之外，区间内其余所有字符都被重新覆盖过，此时需要对第一块位置进行染色；
    - 若 k != l 且 s[k] == s[l] 时则可以将第k个位置染成同第l个位置同样的颜色，且l和k都可以在同一轮染色中完成，所以此时[l, r]的染色次数 f(l, r) 可以由 f(l, k-1)和f(k+1, r) 组成。
    
3. 由此推出状态转移方程：
```
    当 k == 1 时 f(l, r)=min(f(l, r), f(l, l) + f(l+1, r))
    当 k != 1 且 s[k] == s[l] 时 f(l, r)=mln(f(l, r),f(l, k−1) + f(k+1, r))
```

4. 最后返回 f(1, n)。
