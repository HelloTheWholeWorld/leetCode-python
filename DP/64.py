from typing import List
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        if m == 1: return sum(grid[0])
        if n == 1: return sum(grid, key= lambda x: x [0])
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]
        for j in range(1, n):
            grid[0][j] += grid[0][j-1]

        add_base = 0
        while True:
            i = 1
            j = 1 + add_base
            while j > 0:
                if j < n and i < m:
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1])
                if i == m - 1 and j == n - 1:
                    return grid[-1][-1]
                j -= 1
                i += 1
            add_base += 1

def main():
    test = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
    print(Solution().minPathSum(test))

if __name__ == "__main__":
    main()