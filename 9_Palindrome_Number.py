#coding=utf-8
"""
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
"""
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        if s == s[::-1]:
            return True
        return False

    def isPalindrome_faster(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        r = 0
        t = x
        while t:
            r *= 10
            r += t % 10
            t /= 10
        return r == x
