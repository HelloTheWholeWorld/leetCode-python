class Solution:
    def myAtoi(self, str: str) -> int:
        s = str
        s = s.strip()
        if s == "": return 0
        if s[0] not in ['+', '-'] and not s[0].isdigit():
            return 0
        slst = list(s)
        idx = 0
        while idx + 1 < len(slst) and slst[idx + 1].isdigit():
            idx += 1
        
        slst = slst[0:idx+1]
        try:
            num = int(''.join(slst[0:idx+1]))
        except Exception as e:
            return 0
        if num > 2 ** 31 - 1: return 2 ** 31 - 1
        if num < -1 * (2 ** 31): return -1 * (2 ** 31)
        return num

def main():
    str = '+-10'
    print(Solution().myAtoi(str))
if __name__ == "__main__":
    main()
