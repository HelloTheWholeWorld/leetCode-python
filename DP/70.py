# class Solution:
#     def climbStairs(self, n: int) -> int:
#         self.table = {}
#         return self.help_method(n)

#     def help_method(self, n):
#         if n == 0:
#             return 1
#         elif n > 0:
#             if n in self.table:
#                 return self.table[n]
#             else:
#                 num = self.help_method(n - 1) + self.help_method(n - 2)
#                 self.table[n] = num
#                 return num
#         else:
#             return 0
# 不用刻意用dict存储的方法
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 2
        for i in range(2,n):
            dp[i] = dp[i-1]+dp[i-2]
        return dp[n-1]

def main():
    print(Solution().climbStairs(5))

if __name__ == "__main__":
    main()