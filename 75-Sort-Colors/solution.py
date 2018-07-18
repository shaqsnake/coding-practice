class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = 0
        l = -1
        r = len(nums)
        
        while i < r: 
            if nums[i] == 1:
                i += 1
            elif nums[i] == 0:
                l += 1
                nums[l], nums[i] = nums[i], nums[l]
                i += 1
            elif nums[i] == 2:
                r -= 1
                nums[r], nums[i] = nums[i], nums[r]


if __name__ == '__main__':
    l = [2, 1, 0, 0, 2, 1, 1]
    Solution().sortColors(l)
    print(l)