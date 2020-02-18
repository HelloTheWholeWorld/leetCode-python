class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 动态规划
        if m == 1 or n == 1: return 1
        matrix = [[0 for _ in range(m)] for _ in range(n)]
        j = m - 1
        for i in range(n):
            matrix[i][j] = 1
        
        i = n - 1
        for j in range(m):
            matrix[i][j] = 1
        
        minus_base = 2
        row = n
        col = m

        while matrix[0][0] == 0:
            i = row - minus_base + 1
            j = col - 2
            while i < row - 1:
                if i >=0 and j >= 0:
                    matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1]
                i += 1
                j -= 1
            minus_base += 1
        return matrix[0][0]

def main():
    print(Solution().uniquePaths(7, 3))

if __name__ == "__main__":
    main()