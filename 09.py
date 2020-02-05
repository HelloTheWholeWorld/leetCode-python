class Solution:
    def isPalindrome(self, x: int) -> bool:
        xstr = str(x)
        if len(xstr) == 1: return True
        xlst = list(xstr)
        reverse = list(xstr)
        reverse.reverse()
        return True if xlst == reverse else False

def main():
    temp = '-121'
    print(Solution().isPalindrome(temp))

if __name__ == "__main__":
    main()