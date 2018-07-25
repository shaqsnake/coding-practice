import heapq
from random import randint, shuffle

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for n in nums:
            if n not in freq:
                freq[n] = 0
            freq[n] += 1
        
        hq = []
        for key, value in freq.items():
            heapq.heappush(hq, (value, key))
            
        res = heapq.nlargest(k, hq, lambda x: x[0])
        return [ r[1] for r in res]


if __name__ == '__main__':
    nums = []
    for i in range(10):
        nums.extend([i] * randint(1, 9))
    shuffle(nums)
    print(nums)
    print(Solution().topKFrequent(nums, 3))
