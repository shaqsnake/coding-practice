## 题目

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
```
Input: 4
Output: 2
```

Example 2:
```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

## 题解

此题考虑使用二分法，每次迭代找到[0, X]区间的重点mid，然后将mid和x/mid进行比较决定继续在[0, mid-1]或[mid, x]区间继续查找。