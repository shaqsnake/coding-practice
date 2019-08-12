'''
@Author: shaqsnake
@Email: shaqsnake@gmail.com
@Date: 2019-05-09 13:47:55
@LastEditTime: 2019-08-12 15:00:13
@Description: 151. Reverse Words in a String
'''

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(s.split()[::-1])

if __name__ == '__main__':
    s = Solution().reverseWords("the sky is blue")
    print(s)