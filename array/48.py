from typing import List
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # transpose
        N = len(matrix)
        for i in range(N):
            for j in range(0, i):
                matrix[i][j] = matrix[i][j] ^ matrix[j][i]
                matrix[j][i] = matrix[i][j] ^ matrix[j][i]
                matrix[i][j] = matrix[i][j] ^ matrix[j][i]
        
        # print(matrix)
        # 左右互换
        for i in range(N):
            for j in range(N // 2):
                matrix[i][j] = matrix[i][j] ^ matrix[i][N - j - 1]
                matrix[i][N - j - 1] = matrix[i][j] ^ matrix[i][N - j - 1]
                matrix[i][j] = matrix[i][j] ^ matrix[i][N - j - 1]
        # print(matrix)
def main():
    matrix = [
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
    ]
    Solution().rotate(matrix)
    # print(matrix)

if __name__ == "__main__":
    main()