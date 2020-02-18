from typing import List
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        minus = [0, 1, 1, 2]
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        direction_idx = 0
        minus_base = 0
        num = 0
        i = 0
        j = -1
        while True:
            if direction_idx == 0:
                for _ in range(n - minus_base - minus[direction_idx]):
                    j += 1
                    num += 1
                    matrix[i][j] = num
                direction_idx += 1
            elif direction_idx == 1:
                for _ in range(n - minus_base - minus[direction_idx]):
                    i += 1
                    num += 1
                    matrix[i][j] = num
                direction_idx += 1
            elif direction_idx == 2:
                for _ in range(n - minus_base - minus[direction_idx]):
                    j -= 1
                    num += 1
                    matrix[i][j] = num
                direction_idx += 1
            else:
                for _ in range(n - minus_base - minus[direction_idx]):
                    i -= 1
                    num += 1
                    matrix[i][j] = num
                direction_idx = 0
                minus_base += 2
            if num == n ** 2:
                return matrix
          
def main():
    print(Solution().generateMatrix(3))

if __name__ == "__main__":
    main()