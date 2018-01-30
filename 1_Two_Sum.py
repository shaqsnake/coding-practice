"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if target == nums[i] + nums[j]:
                    return [i, j]
        return None

    def twoSum_on(self, nums, target):
        """
        O(n) solution
        """
        buff_dict = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in buff_dict:
                return [buff_dict[m], i]
            else:
                buff_dict[n] = i


if __name__ == '__main__':
    res = Solution().twoSum_on([1, 3, 5, 6], 4)
    assert res == [0, 1]
