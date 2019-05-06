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

    def twoSum_On(self, nums, target):
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
    res = Solution().twoSum_On([1, 3, 5, 6], 4)
    assert res == [0, 1]
