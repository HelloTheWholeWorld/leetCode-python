class Solution:
    def mySqrt(self, x: int) -> int:
        if x in [0, 1]: return x
        return self.help_method(x, 0, x)

    def help_method(self, x, left, right):
        if left ** 2 == x:
            return left
        if right == left + 1 and left ** 2 < x and right ** 2 > x:
            return left
        mid = int((left + right) / 2)
        return self.help_method(x, mid, right) if mid ** 2 <= x else self.help_method(x, left, mid)
def main():
    print(Solution().mySqrt(9))

if __name__ == "__main__":
    main()