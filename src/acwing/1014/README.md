# 1014. 登山

## 题目

五一到了，ACM队组织大家去登山观光，队员们发现山上一个有N个景点，并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。

同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。

队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？

#### 输入格式

第一行包含整数N，表示景点数量。

第二行包含N个整数，表示每个景点的海拔。

#### 输出格式

输出一个整数，表示最多能浏览的景点数。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\2%20\leq%20N%20\leq%201000)

#### 输入样例：

```
8
186 186 150 200 160 130 197 220
```

#### 输出样例：

```
4
```

## 题解

### 动态规划 O(n^2)

类似[1017. 怪盗基德的滑翔翼](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/1017/)，需要遍历两轮来求一个单调上升又单调下降的最长子序列。
