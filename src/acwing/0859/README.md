<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-10-22 11:46:57
 * @Description: Acwing 859
 -->

# 859. Kruskal算法求最小生成树

## 题目

给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

给定一张边带权的无向图G=(V, E)，其中V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|。

由V中的全部n个顶点和E中n-1条边构成的无向连通子图被称为G的一棵生成树，其中边的权值之和最小的生成树被称为无向图G的最小生成树。

#### 输入格式

第一行包含两个整数n和m。

接下来m行，每行包含三个整数u，v，w，表示点u和点v之间存在一条权值为w的边。

#### 输出格式

共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20n%20\leq%2010^5),

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20m%20\leq%202\times10^5),

图中涉及边长绝对值均不超过1000。

#### 输入样例：

```
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
```

#### 输出样例：

```
6
```

## 题解

### Kruskal算法

此题可以参考[Prim算法](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/0858/)求解最小生成树，但题目给出的点数和边数较大，是一个稀疏图，所以可以用更高效的Kruskal算法。

Kruskal算法的过程如下：

1. 首先将所有边和其权重都存储在一个结构体数组中，然后按照边权重的大小从小到大排序；
2. 从小到大循环遍历所有边，每次循环检查边的两个端点是否连通（即是否都在最小生成树的集合中），如果不连通就将此边加入到集合中，此步可以用并查集的方法来实现；
3. 最后集合中保存的即是此图的最小生成树。

同[Prim算法](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/0858/)一样，如果需要统计最小生成树的边权之和，可以在循环迭代的过程中累加即可。
