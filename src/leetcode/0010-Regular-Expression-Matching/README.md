<!--
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 11:34:26
 * @LastEditTime: 2019-09-16 14:17:14
 * @Description: 10. Regular Expression Matching
 -->

## 题目

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:
```
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

Example 2:
```
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

Example 3:
```
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

Example 4:
```
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
```

Example 5:
```
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```

## 题解

### 动态规划 O(nm)

1. 用一个二维数组f[i][j]表示字符串s的第i个字符与字符串p第j个字符的匹配状态，状态用bool类型true/false表示；
2. 更具匹配串p来分情况更新状态：

    - p的第j个字符如果为'.'，或者与s的第i个字符相同，那么f[i][j]的状态应该来自于f[i-1][j-1]的状态
    - p的第j个字符如果为'*',此时又分两种情况：
        
        - p中第j个和第j-1个字符可以忽略（因为'*'可以表示匹配0个），此时f[i][j]的状态因该来源于f[i][j-2];
        - p中第j-1个字符与s中的第i个字符相等，或者为'.'，此时表示s[i]与p[j-1]可以匹配，那么f[i][j]的状态应该来源于f[i-1][j];

3. 由此推出状体转移方程为：

```
    f[i][j] = f[i-1][j-1] 当p[j] == '.' 或 p[j] == s[i];
    f[i][j] = f[i][j-2] 当p[j] == '*'
    f[i][j] = f[i-1][j] 当p[j] == '*' 且 p[j-1] == s[i];
```

4. 最后输出f[n][m]保存的状态。
