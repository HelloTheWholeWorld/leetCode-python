class Solution:
    def reverse(self, x: int) -> int:
        if x == 0: return x
        xlst = list(str(abs(x)))
        flag = x > 0
        xlst.reverse()
        ret = int(''.join(xlst).lstrip('0'))
        ret =  ret if flag else -1 * ret
        if not (ret >= - (2 ** 31) and ret <= (2 ** 31) - 1):
            return 0
        return ret

def main():
    x = 1200
    print(Solution().reverse(x))

if __name__ == "__main__":
    main()