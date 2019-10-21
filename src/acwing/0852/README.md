<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-10-21 11:55:06
 * @Description: Acwing 852
 -->

# 851. spfa求最短路

## 题目

给定一个n个点m条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

#### 输入格式

第一行包含整数n和m。

接下来m行每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

#### 输出格式

如果图中存在负权回路，则输出“Yes”，否则输出“No”。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20n%20\leq%202000),

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20m%20\leq%2010000),

图中涉及边长绝对值均不超过10000。

#### 输入样例：

```
3 3
1 2 -1
2 3 4
3 1 -4
```

#### 输出样例：

```
Yes
```

## 题解

### spfa

此题有负权边，所以首先考虑spfa算法，可以参考[851. spfa求最短路](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/0851/)。

需注意此题是要判断是否存在负环，所以在[851. spfa求最短路](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/0851/)的基础上需要一个额外的数组cnt[1..n]来记录起点到每个点的最短路径中边的个数，在spfa松弛过程中可以根据条件 cnt[j] >= n 来判断是否存在负环，因为n个点的最短路径的长度一旦大于等于n，说明这条路径上一共有n + 1个点，那么就一定存在一个环，且因为这个环是在松弛过程中发现的，所以这个环一定是一个负环。

注：此题是求所有路径中是否包括负环，所以在队列初始化阶段需要将所有点都放入队列中。
