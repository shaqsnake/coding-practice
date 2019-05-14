class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        queue = []
        queue.append((n, 0))
        freq = {}
        
        while queue:
            (n, cnt) = queue.pop(0)
            if n == 0:
                return cnt
            
            i = 1
            while n - i*i >= 0:
                if n - i*i not in freq:
                    queue.append((n - i*i, cnt+1))
                    freq[n-i*i] = cnt+1
                i += 1
                
        

if __name__ == '__main__':
    print(Solution().numSquares(12))