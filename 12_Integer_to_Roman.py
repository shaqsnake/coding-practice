# coding=utf-8
"""
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
"""
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0 or num > 3999:
            return None

        l = [['I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'], # 0-9
            ['X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'], # 10-90
            ['C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'], # 100-900
            ['M', 'MM', 'MMM']] # 1000-3000
        i = 0
        s = []
        while num > 0:
            if num%10-1 >= 0:
                s.append(l[i][num%10-1])
            i += 1
            num = num // 10
        return ''.join(s[::-1])

if __name__ == '__main__':
    print(Solution().intToRoman(1776))
