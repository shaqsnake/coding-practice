"""
mplement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
"""

class Solution(object):
    def myAtoi_by_re(self, str):
        """
        :type str: str
        :rtype: int
        """
        import re
        str = str.strip()
        str = re.findall('(^[\+\-0]*\d+)\D*', str)

        try:
            res = int(''.join(str))
            return max(-2**31, min(res, 2**31-1))
        except:
            return 0

    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if len(str) == 0:
            return 0
        l = list(str.strip())
        s = 1
        if l[0] == '-':
            s = -1
        if l[0] in ['+', '-']:
            del l[0]

        res = 0
        for i in range(len(l)):
            if l[i].isdigit():
                res = res * 10 + int(l[i])
            else:
                break

        return max(-2**31, min(s*res, 2**31-1))

if __name__ == '__main__':
    assert Solution().myAtoi_by_re('+-2') == 0
    assert Solution().myAtoi('+-2') == 0
