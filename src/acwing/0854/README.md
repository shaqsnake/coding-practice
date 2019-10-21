<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-10-21 12:50:25
 * @Description: Acwing 854
 -->

# 854. Floyd求最短路

## 题目

给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定k个询问，每个询问包含两个整数x和y，表示查询从点x到点y的最短距离，如果路径不存在，则输出“impossible”。

数据保证图中不存在负权回路。

#### 输入格式

第一行包含三个整数n，m，k

接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

接下来k行，每行包含两个整数x，y，表示询问点x到点y的最短距离。

#### 输出格式

共k行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出“impossible”。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20n%20\leq%200),

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20k%20\leq%20n^2),

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20m%20\leq%2020000),

图中涉及边长绝对值均不超过10000。

#### 输入样例：

```
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
```

#### 输出样例：

```
impossible
1
```

## 题解

### Floyd O(n^3)

此题是一个图的多源最短路问题，所以考虑使用Floyd算法。实际上就是DP的过程。

对于一个点i到点j的最短路径d(i, j)可以由前一个状态d(i, k) + d(k, j)转移而来，所以状态转移方程为：
```
d(i, j) = min(d(i, j), d(i, k) + d(k, j)) 其中k = 0..n
```

而d(i, j)可用一个二维的邻接矩阵d[1..n][1..n]来表示。

最终伪代码如下：
```
for k <- 1..n:
    for i <- 1..n:
        for j <- 1..n:
            d[i, j] = min(d[i, j], d[i, k] + d[k, j]);
        end for
    end for
end for
```
