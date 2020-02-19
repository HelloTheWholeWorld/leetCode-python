from typing import List
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m == 0: return False
        n = len(matrix[0])
        if n == 0: return False
        left = 0
        right = m * n - 1
        while left <= right:
            idx = (left + right) // 2
            num = matrix[idx // n][idx % n]
            if num == target:
                return True
            elif num < target:
                left = idx + 1
            else:
                right = idx - 1
        return False

def main():
    matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
    ]
    target = 3
    print(Solution().searchMatrix(matrix, target))

if __name__ == "__main__":
    main()