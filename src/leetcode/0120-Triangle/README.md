<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-08 14:04:59
 * @LastEditTime: 2019-09-08 14:51:11
 * @Description: 120. Triangle
 -->

## 题目

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

## 题解

### 朴素的动态规划 O(n^2)

1. 用二维的空间f[i][j]来表示三角形中从坐标(0, 0)到坐标(i, j)之间最短路径的距离；
2. 根据路径的规则，对于坐标(i,j)来说，它的上一个路径只能来自于(i-1, j-1)和(i-1, j)两个点；
3. 所以推导出状态转移方程为： f[i][j] = min(f[i-1][j-1] + triangle[i][j], f[i-1][j] + triangle[i][j]);
4. 最后，f[n-1]就存储了从起点所有终点的最短路径，遍历一遍求出最短的一条的距离和即可。

注：在迭代更新f[i][j]状态的过程中，需要注意判断(i-1, j-1)和(i-1, j)的边界条件，即：

- 当j=0时，(i, j)此时处于三角形的左边线上，上一个路径只可能有(i-1, j)；
- 当j=i时，(i, j)此时处于三角形的右边线上，上一个路径只可能有(i-1, j-1)。

### 滚动数组优化的动态规划

根据上面推出的状态转移方程：f[i][j] = min(f[i-1][j-1] + triangle[i][j], f[i-1][j] + triangle[i][j])，可以看出f[i][j]的状态只和f[i-1][j-1]及f[i-1][j]相关，所以实际上我们只需要在迭代过程中存储f[i-1]和f[i]的状态即可，即每次用f[i-1]的状态来更新f[i]的状态。

所以可以把f[n-1][n-1]的状态数组优化成f[2][n-1]，相互交替更新两行的状态即可。

注：滚动跟新两行的状态可以通过 ```mod 2``` 的方式进行，此题可以用更简洁的 ```i & 1``` 的方法来实现，相见代码。

### 自底向上的动态规划

上面两种方法都是从三角形的顶点即(0, 0)开始从上往下依次更新每一层的路径状态，实际上从三角形的最后一层自底向上也是可以的，这种方式可以不申请额外的数组空间来保存状态，在原数组上更新即可，此时状态转移方程为：f[i][j] = f[i][j] + min(f[i+1][j], f[i+1][j+1])。

注：此种方式无需考虑边界的情况。