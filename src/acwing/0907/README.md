<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-09-17 17:57:41
 * @Description: Acwing 906
 -->

# 907. 区间覆盖

## 题目

给定N个闭区间[ai,bi]以及一个线段区间[s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出-1。

#### 输入格式

第一行包含两个整数s和t，表示给定线段区间的两个端点。

第二行包含整数N，表示给定区间数。

接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

#### 输出格式

输出一个整数，表示所需最少区间数。

如果无解，则输出-1。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20N%20\leq%2010^{5})

![](http://latex.codecogs.com/gif.latex?\\-10^{9}%20\leq%20a_{i}%20\leq%20b_{i}%20\leq%2010^{9})

![](http://latex.codecogs.com/gif.latex?\\-10^{9}%20\leq%20s%20\leq%20t%20\leq%2010^{9})

#### 输入样例：

```
1 5
3
-1 3
2 4
3 5
```

#### 输出样例：

```
2
```

## 题解

### 贪心算法 O(nlogn)

1. 先按所有区间的左端点从小到大进行排序；
2. 遍历所有区间，每轮找出可以覆盖目标且右端点最大的区间，用此区间的右端点更新目标的左端点；
3. 如果发现无法覆盖或者已经能完全覆盖目标，提前退出循环；
4. 最后输出方案数即可。