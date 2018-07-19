class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        j = -1
        sum = 0
        res = len(nums) + 1
        
        while i < len(nums)-1:
            if j < len(nums)-1 and sum < s:
                j += 1
                sum += nums[j]
                continue
                
            if sum >= s:
                res = min(res, j-i+1)
                sum -= nums[i]
            i += 1
        
        if res == len(nums) + 1:
            return 0
        return res