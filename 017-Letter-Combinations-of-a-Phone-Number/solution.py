class Solution(object):
    def __init__(self):
        self.dmap = [
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
            " "
        ]
        self.res = []
    
    def findComb(self, digit, left_digits, c):
        if len(left_digits) <= 0:
            for letter in self.dmap[int(digit)]:
                c += letter
                self.res.append(c)
                c = c[:-1]
            return
        
        for letter in self.dmap[int(digit)]:
            c += letter
            self.findComb(left_digits[0], left_digits[1:], c)
            c = c[:-1]
    
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
        if len(digits) < 1:
            return []
        
        self.findComb(digits[0], digits[1:], "")
        
        return self.res


if __name__ == '__main__':
    import doctest
    doctest.testmod(verbose=True)