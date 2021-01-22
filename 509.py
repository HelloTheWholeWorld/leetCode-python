class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif  n == 1 or n == 2:
            return 1
        else:
            i_minus_2 = 1
            i_minus_1 = 1
            s = 0
            for _ in range(n - 2):
                s = i_minus_2 + i_minus_1
                i_minus_2 = i_minus_1
                i_minus_1 = s
            return s

if __name__ == '__main__':
    n = 30
    print(Solution().fib(n))