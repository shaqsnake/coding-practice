# 2. 01背包问题

## 题目

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

#### 输入格式

第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20N,V%20\leq%201000)

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20v_i,w_i%20\leq%201000)

#### 输入样例：

```
4 5
1 2
2 4
3 4
4 5
```

#### 输出样例：

```
8
```

## 题解

### DP

最基础的背包问题，状态表示可以使用一个二维数组f[1..N][1..V]，其中f[i][j]就表示了选择了i件物品，且背包体积为j时物品总价值。

状态可以划分为：

1. 不选择第i件物品，此时f[i][j]可由f[i-1][j]的状态推导而来；
2. 可选择第i件物品，且背包的容量足够放下，此时f[i][j]的状态由f[i-1][j-v[i]] + w[i] 和 f[i][j] 的最优解推导而来。

所以状态转移方程为：

```
f[i][j] = f[i-1][j] 当不选i时
f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]) 当可选i时
```

注：01背包问题可以在空间上进行优化将状态数组从二维压缩到一维，具体见实现代码。