'''
@Author: shaqsnake
@Email: shaqsnake@gmail.com
@Date: 2019-05-09 13:47:55
@LastEditTime: 2019-08-13 10:26:10
@Description: 6. ZigZag Conversion
'''


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
            elif cur == numRows - 1:
                step = -1
            cur += step
        return ('').join(L)
