from copy import copy


class Solution(object):
    def __init__(self):
        self.res = []
    
    def _searchComb(self, n, k, start, c):
        if len(c) == k:
            r = copy(c)
            self.res.append(r)
            return
        
        i = start
        while i <= n:
            c.append(i)
            self._searchComb(n, k, start+1, c)
            c.pop()
            start += 1
            i += 1

        return
        
            
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if n <= 0 or k <= 0 or n < k:
            return []
        
        self._searchComb(n, k, 1, [])
        
        return self.res


if __name__ == '__main__':
    print(Solution().combine(4, 2))