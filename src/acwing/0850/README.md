<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-10-17 10:25:28
 * @Description: Acwing 850
 -->

# 850. Dijkstra求最短路 II

## 题目

给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

#### 输入格式

第一行包含整数n和m。

接下来m行每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

#### 输出格式

输出一个整数，表示1号点到n号点的最短距离。

如果路径不存在，则输出-1。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20n,m%20\leq%2010^5),

图中涉及边长均不超过10000。

#### 输入样例：

```
3 3
1 2 2
2 3 1
1 3 4
```

#### 输出样例：

```
3
```

## 题解

### Dijkstra

首先根据题意来决定用哪一种最短路算法，此题是一个单源图的最短路问题，且图中不包括负权边，所以考虑使用Dijkstra算法。
可参考[849. Dijkstra求最短路 I](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/0849/)。

此题因为是一个稠密图，所以需要用邻接表来存储所有边和边的权重，同样除了朴素的Dijkstra算法外，还可以用堆来优化更新的过程。
