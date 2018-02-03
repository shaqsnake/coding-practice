#coding=utf-8
"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""
class Solution(object):
    # O(m+n)
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        nums1.sort()
        l = len(nums1)
        if l%2 == 0:
            return (nums1[l/2 -1] + nums1[l/2])/2.0
        else:
            return nums1[(l-1)/2]

    # O(mlogm+nlogn))
    def findMedianSortedArrays_plus(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = len(nums1) + len(nums2)
        if l%2 == 0:
            return (self.kth(nums1, nums2, l/2) + self.kth(nums1, nums2, l/2-1))/2
        else:
            return self.kth(nums1, nums2, l/2)

    def kth(self, a, b, k):
        """
        通过二分查找法从两个已排序的List中查找排在第k位的数
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # 递归退出条件，即已找到第k位数
        if not a:
            return b[k]
        if not b:
            return a[k]
        # 先分别找出两个数组a, b的中位数ma, mb及其index ia, ib
        ia = len(a)/2
        ib = len(b)/2
        ma = a[ia]
        mb = b[ib]
        # 先比较ia+ib与k的大小,如果 ia+ib<k，说明第k位数肯定在两个数组较大的一侧
        if ia + ib < k:
        # 再比较两个中位数 ma与mb 大小，如果ma<mb，说明第k位数肯定不在a较小的一侧，可以把ma及其的左侧截去，再递归查找截去后的a',b的第k-ia-1位数
            if ma < mb:
                return self.kth(a[ia+1:], b, k-ia-1)
        # 同理如果 mb<ma,则截去mb及其左侧
            else:
                return self.kth(a, b[ib+1:], k-ib-1)
        # 如果 ia+ib>k，说明第k位数在两个数组较大的一侧，同上逻辑类推截去其中一个数组右侧后，继续递归查找第k位数。
        else:
            if ma < mb:
                return self.kth(a, b[:ib], k)
            else:
                return self.kth(a[:ia], b, k)



if __name__ == '__main__':
    n1 = [1, 2, 5]
    n2 = [3, 4]
    print(Solution().findMedianSortedArrays_plus(n1, n2))
