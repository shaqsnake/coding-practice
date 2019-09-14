<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-14 14:28:34
 * @LastEditTime: 2019-09-14 15:11:49
 * @Description: 518. Coin Change 2
 -->

## 题目

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:
```
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

Example 2:
```
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

Example 3:
```
Input: amount = 10, coins = [10] 
Output: 1
``` 

Note:

You can assume that

- 0 <= amount <= 5000
- 1 <= coin <= 5000
- the number of coins is less than 500
- the answer is guaranteed to fit into signed 32-bit integer

## 题解

### 动态规划 O(n^3)

1. 用二维数组f[i][j]表示用到第i个硬币时总价值为j的方案数，比如f[3][5] = 4表示用到第3个硬币构成总价值为5的方案数为4个；
2. 状态f[i][j]的推导类似于完全背包问题，第i个硬币构成的方案可以由第i-1个硬币的方案基础上推出，再从f[i-1]到f[i]时，第i个硬币应该有0到k种选法，只要满足 k * coins[i] <= j 即可；
3. 推出状态转移方程为：f[i][j] = f[i-1][j] + f[i-1][j-c] + f[i-1][j-2c] + ... + f[i-1][j-kc]， 其中 j >= kc;
4. 最后迭代求出最后一组状态f[n][m]即可。

### 动态规划 O(n^2)

1. 根据上述的动态规划转移方程可知 f[i][j-c] = f[i-1][j-c] + f[i-1][j-2c] + ... + f[i-1][j-kc], 可得到 f[i][j] = f[i-1][j] + f[i-1][j-c]，所以f[i][j]的状态只和f[i-1]的状态相关，所以可以用一个滚动数组来保存所有状态；
2. 最后可推出状态转移方程为 f[j] = f[j] + f[j-c];
