from copy import copy

class Solution(object):
    def __init__(self):
        self.res = []
    
    def _travelPermute(self, nums, p):
        if not nums:
            self.res.append(copy(p))
            return
        
        for i in range(len(nums)):
            p.append(nums.pop(i))
            self._travelPermute(nums, p)
            nums.insert(i, p.pop())
        
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 0:
            return []
        
        self._travelPermute(nums, [])
        return self.res


if __name__ == '__main__':
    print(Solution().permute([1, 2, 3]))