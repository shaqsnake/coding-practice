"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        # cur is the point to mark the first char that not duplicate before
        cur = res = 0
        for i, n in enumerate(s):
            if n in d and cur <= d[n]:
                # if find a duplicate char and the char is behind the cur, move cur next to this char
                cur = d[n] + 1
            else:
                # calculate the longest substring
                res = max(res, i-cur+1)
            d[n] = i
        return res


if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("tmmzuxt"))
