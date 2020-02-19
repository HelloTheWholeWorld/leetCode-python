class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0: return 1.0
        if n == 1: return x
        if n == -1: return 1/x
        if n < 0:
            x = 1 / x
            n = -n
        # 分治加打表保存
        table = {}
        return self.help_method(table, x, n)

    def help_method(self, table, x, n):
        if n == 1:
            return x
        if n in table:
            return table[n]
        left_n = int(n / 2)
        right_n = n - left_n
        left = table[left_n] if left_n in table else self.help_method(table, x, left_n)
        right = table[right_n] if right_n in table else self.help_method(table, x, right_n)
        table[n] = left * right
        return left * right

def main():
    print(Solution().myPow(2.00, -2))

if __name__ == "__main__":
    main()