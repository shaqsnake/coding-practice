'''
@Author: shaqsnake
@Email: shaqsnake@gmail.com
@Date: 2019-05-09 13:47:55
@LastEditTime: 2019-08-13 15:10:37
@Description: 
'''


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
                res = max(res, i - cur + 1)
            d[n] = i
        return res

    def lengthOfLongestSubstring2(self, s):
        """
        :type s: str
        :rtype: int
        """
        f = [0] * 256
        l = 0
        r = -1
        res = 0

        while l < len(s):
            if r + 1 < len(s) and f[ord(s[r + 1])] == 0:
                r += 1
                f[ord(s[r])] += 1
            else:
                f[ord(s[l])] -= 1
                l += 1

            res = max(res, r - l + 1)

        return res
