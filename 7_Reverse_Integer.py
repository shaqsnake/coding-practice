#coding=utf-8
"""
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = list(str(x))
        n = len(l)
        i = 0
        while i < n-i:
            # 如果输入为负数
            if l[0] == '-':
                if i>0:
                    l[i], l[n-i] = self.swap(l[i], l[n-i])
            #　如果输入为正数
            else:
                l[i], l[n-i-1] = self.swap(l[i], l[n-i-1])
            i += 1
        res = int(''.join(l))
        # 判断结果是否超过了32bit，其中1bit是符号位，[-2**31, 2**31)
        if res >= 2**31 or res < -2**31:
            return 0
        return res

    def swap(self, a, b):
        return b, a

    def reverse_shorter(self, x):
        """
        参考Discuss
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(`s*x`[::-1])
        return s*r*(r < 2**31)



if __name__ == '__main__':
    x = -123
    assert Solution().reverse(x) == -321
    assert Solution().reverse_shorter(x) == -321
