<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 15:58:00
 * @LastEditTime: 2019-09-18 19:11:06
 * @Description: Acwing 1015
 -->

# 913. 排队打水

## 题目

Hello Kitty想摘点花生送给她喜欢的米老鼠。

她来到一片有网格状道路的矩形花生地(如下图)，从西北角进去，东南角出来。

地里每个道路的交叉点上都有种着一株花生苗，上面有若干颗花生，经过一株花生苗就能摘走该它上面所有的花生。

Hello Kitty只能向东或向南走，不能向西或向北走。

问Hello Kitty最多能够摘到多少颗花生。

![](https://cdn.acwing.com/media/article/image/2019/09/12/19_a8509f26d5-1.gif)

#### 输入格式

第一行是一个整数T，代表一共有多少组数据。

接下来是T组数据。

每组数据的第一行是两个整数，分别代表花生苗的行数R和列数 C。

每组数据的接下来R行数据，从北向南依次描述每行花生苗的情况。每行数据有C个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目M。

#### 输出格式

对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20T%20\leq%20100)

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20R,C%20\leq%20100)

![](http://latex.codecogs.com/gif.latex?\\1%20\leq%20M%20\leq%20100)

#### 输入样例：

```
2
2 2
1 1
3 4
2 3
2 3 4
1 6 5
```

#### 输出样例：

```
8
16
```

## 题解

### 动态规划 O(n^2)

类似 [Leetcode 63. Unique Paths II](https://github.com/shaqsnake/coding-practice/blob/master/src/leetcode/0063-Unique-Paths-II/) 和 [120. Triangle](https://github.com/shaqsnake/coding-practice/blob/master/src/leetcode/0120-Triangle/)
