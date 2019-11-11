# 482. 合唱队形

## 题目

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。     

合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，  则他们的身高满足T1<…<Ti>Ti+1>…>TK(1≤i≤K)。     

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

#### 输入格式

输入的第一行是一个整数N，表示同学的总数。

第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高(厘米)。

#### 输出格式

输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

#### 数据范围

![](http://latex.codecogs.com/gif.latex?\\2%20\leq%20N%20\leq%20100),

![](http://latex.codecogs.com/gif.latex?\\130%20\leq%20T_i%20\leq%20230)

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

类似[1014. 登山](https://github.com/shaqsnake/coding-practice/blob/master/src/acwing/1014/)，需要遍历两轮来求一个单调上升又单调下降的最长子序列。