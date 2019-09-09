<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-09 11:09:46
 * @LastEditTime: 2019-09-09 11:24:05
 * @Description: 72. Edit Distance
 -->

## 题目

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:
```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

Example 2:
```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```
## 题解

### 动态规划 O(n^2)

1. 用二维数组f[i][j]来表示字符串a[i]通过增删改转变到b[j]的最小操作数；
2. f[i][j]的状态表示可以分为增删改三种情况：

    - a[i]是通过一次删除操作转变为b[j]的；
    - a[i]是通过一次增加操作转变为b[j]的；
    - a[i]是通过一次修改操作转变为b[j]的；
    - a[i]不通过任何操作转变为b[j];

3. 由此推出状态转移方程 
    
    - f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1)；
    - a[i] == b[j]时，f[i][j] = min(f[i][j], f[i-1][j-1])；
    - a[i] != b[j]时，f[i][j] = min(f[i][j], f[i-1][j-1] + 1);

4. 最后输出f[n][m]的值即为整个操作的最小操作数。
