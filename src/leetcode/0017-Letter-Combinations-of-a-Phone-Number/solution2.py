'''
@Author: shaqsnake
@Email: shaqsnake@gmail.com
@Date: 2019-05-09 13:47:55
@LastEditTime: 2019-08-14 10:54:43
@Description: 
'''
#coding=utf-8
"""
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
"""
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        >>> Solution().letterCombinations('')
        []
        >>> Solution().letterCombinations('2')
        ['a', 'b', 'c']
        >>> Solution().letterCombinations('23')
        ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
        """
        if len(digits) == 0:
            return []
        d = {'1': '',
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
            '0': ' '
            }
        res = list(d[digits[0]])
        for i in range(1, len(digits)):
            res = self.prod_str(res, d[digits[i]])
        return res

    def prod_str(self, a, b):
        res = []
        for i in a:
            for j in b:
                res.append(i+j)
        return res

    # 利用python的reduce方法
    def letterCombinations_reduce(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        >>> Solution().letterCombinations_reduce('')
        []
        >>> Solution().letterCombinations_reduce('2')
        ['a', 'b', 'c']
        >>> Solution().letterCombinations_reduce('23')
        ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
        """
        if len(digits) == 0:
            return []
        d = {'1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz', '0': ' '}
        return reduce(lambda acc, digit: [x+y for x in acc for y in d[digit]], digits, [''])

    # 最简洁的写法
    def letterCombinations_oneline(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        >>> Solution().letterCombinations_online('')
        []
        >>> Solution().letterCombinations_online('2')
        ['a', 'b', 'c']
        >>> Solution().letterCombinations_online('23')
        ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
        """
        d = {'1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz', '0': ' '}
        return [x+y for x in d.get(digits[:1], '')
                    for y in self.letterCombinations_online(digits[1:]) or ['']] or []

if __name__ == '__main__':
    import doctest
    doctest.testmod(verbose=True)
