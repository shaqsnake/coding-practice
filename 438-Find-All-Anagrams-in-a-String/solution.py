class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        f = [0] * 256
        for x in p:
            f[ord(x)] += 1
        
        l = r = 0
        cnt = len(p)
        while r < len(s):
            if f[ord(s[r])] > 0:
                cnt -= 1
            f[ord(s[r])] -= 1
            r += 1
            
            if cnt == 0:
                res.append(l)
            
            if r - l >= len(p):
                if f[ord(s[l])] >= 0:
                    cnt += 1
                f[ord(s[l])] += 1
                l += 1
                
        return res

if __name__ == '__main__':
    print(Solution().findAnagrams("abcbac", "abc"))