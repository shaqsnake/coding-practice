# coding=utf-8
import timeit, functools
"""
Write a function to find the longest common prefix string amongst an array of strings.
"""
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not len(strs):
            return ""
        lcp = strs[0]
        found = False
        while lcp and not found:
            found = True
            for s in strs:
                if not s.startswith(lcp):
                    found = False
                    lcp = lcp[:-1]
                    break
        return lcp

    def longestCommonPrefix_zip(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        for i, letter_group in enumerate(zip(*strs)):
            if len(set(letter_group)) > 1:
                return strs[0][:i]
        else:
            return min(strs)

def wrapper(func, *args, **kwargs):
    def wrapped():
        return func(*args, **kwargs)
    return wrapped

if __name__ == '__main__':
    strs = ["abc", "abb", "abdd"]
    print(Solution().longestCommonPrefix(strs))
    t1 = timeit.Timer(functools.partial(Solution().longestCommonPrefix, strs))
    print t1.timeit(5)
    print(Solution().longestCommonPrefix_zip(strs))
    t2 = timeit.Timer(functools.partial(Solution().longestCommonPrefix_zip, strs))
    print t2.timeit(5)
