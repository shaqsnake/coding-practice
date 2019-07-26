'''
@Author: shaqsnake
@Email: shaqsnake@gmail.com
@Date: 2019-07-26 10:50:38
@LastEditTime: 2019-07-26 10:51:00
@Description: 74. Search a 2D Matrix
'''


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or target is None:
            return False

        rows, cols = len(matrix), len(matrix[0])
        low, high = 0, rows * cols - 1

        while low <= high:
            mid = (low + high) // 2
            num = matrix[mid // cols][mid % cols]
            if num == target:
                return True
            elif num < target:
                low = low + 1
            else:
                high = high - 1

        return False
