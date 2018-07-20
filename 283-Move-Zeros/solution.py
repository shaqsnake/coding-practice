class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        cur = 0
        for n in nums:
            if n != 0:
                nums[cur] = n
                cur += 1
                
        while cur < len(nums):
            nums[cur] = 0
            cur += 1