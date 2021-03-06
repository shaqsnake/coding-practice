<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-10-22 11:46:57
 * @Description: Acwing 860
 -->

# 860. 染色法判定二分图

## 题目

给定一个n个点m条边的无向图，图中可能存在重边和自环。

请你判断这个图是否是二分图。

#### 输入格式

第一行包含两个整数n和m。

接下来m行，每行包含两个整数u和v，表示点u和点v之间存在一条边。

#### 输出格式

如果给定图是二分图，则输出“Yes”，否则输出“No”。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20n,m%20\leq%2010^5),

#### 输入样例：

```
4 4
1 3
1 4
2 3
2 4
```

#### 输出样例：

```
Yes
```

## 题解

### DFS

首先构建一个邻接表来存储无向图，然后用DFS来遍历每个点，每遍历每个点时：
    
1. 如果该点没有染色，那就给此点染上和相邻点不同的颜色；
2. 如果该点已经染色，则要判读此颜色和相邻点的颜色是否相同，如果相同说明有冲突；

最后如果遍历完所有点依然没有出现冲突，说明此图可以构建成一个二分图。
