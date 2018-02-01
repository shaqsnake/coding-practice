#coding=utf-8
"""
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # start指针记录满足条件substring的起始
        start = 0
        # max_length 记录满足条件substring的最长长度
        max_length = 1
        # 遍历s, 用cur记录当前的位置
        for cur in range(len(s)):
            # 对于基数长度且满足镜像条件的substring，如“aba”， “bcacb”等
            if cur - max_length >= 1 and s[cur-max_length-1:cur+1] == s[cur-max_length-1:cur+1][::-1]:
                start = cur - max_length - 1 # cur游标移动到满足条件处
                max_length += 2 # max_length递增2步
                continue # 已经完成基数长度的检测，跳过偶数长度部分
            # 对于偶数长度且满足镜像条件的substring，如“bb”，“baab”等
            if cur - max_length >= 0 and s[cur-max_length:cur+1] == s[cur-max_length:cur+1][::-1]:
                start = cur - max_length
                max_length += 1
        # 返回最长的镜像substring
        return s[start:start+max_length]

if __name__ == '__main__':
    s = "babcba"
    print(Solution().longestPalindrome(s))
