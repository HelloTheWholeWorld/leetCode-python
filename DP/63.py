from typing import List
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if m == 1:
            return 0 if  1 in obstacleGrid[0] else 1
        if n == 1:
            return 0 if [1] in obstacleGrid else 1
        if obstacleGrid[-1][-1] == 1: return 0
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                else:
                    obstacleGrid[i][j] = -1
        obstacleGrid[-1][-1] = 1
        minus_base = 1
        while True:
            i = m - 1
            j = n - 1 - minus_base
            while j < n:
                if i >= 0 and j >= 0 and obstacleGrid[i][j] != 0:
                    right = obstacleGrid[i][j + 1] if j + 1 <= n - 1 else 0
                    down = obstacleGrid[i + 1][j] if i + 1 <= m - 1 else 0
                    obstacleGrid[i][j] = right + down
                if i == 0 and j == 0:
                    return obstacleGrid[0][0]
                i -= 1
                j += 1
            minus_base += 1

def main():
    test = [[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[1,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0]]
    print(Solution().uniquePathsWithObstacles(test))

if __name__ == "__main__":
    main()