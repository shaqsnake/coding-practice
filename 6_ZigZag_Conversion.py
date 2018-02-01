#coding=utf-8
"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
"""
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # 边界条件
        if numRows <= 1 or len(s) < numRows:
            return s

        # 先根据numRows的大小n构建大小n的List，用来缓存每一行的字符
        L = [''] * numRows
        cur = step = 0
        # 遍历s，把s中的字符依次放入List，在抵达边界时折返
        for x in s:
            # 把字符逐一放入对应的List
            L[cur] += x
            # 当指针抵达上届时折返
            if cur == 0:
                step = 1
            # 当指针抵达下界时折返
            elif cur == numRows-1:
                step = -1
            cur += step
        return ('').join(L)


if __name__ == '__main__':
    s = "PAYPALISHIRING"
    print(Solution().convert(s, 4))
