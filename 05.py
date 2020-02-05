class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == '':
            return ''
        length = len(s)
        hashmap = [[False for i in range(length)] for i in range(length)]
        # 间隔是0
        for i in range(length):
            hashmap[i][i] = True
        # 间隔是1
        for i in range(length - 1):
            hashmap[i][i+1] = True if s[i] == s[i+1] else False
        
        # 间隔为2及以上
        for interval in range(2, length):
            for i in range(length - interval):
                if hashmap[i + 1][i + interval - 1] and s[i] == s[i + interval]:
                    hashmap[i][i + interval] = True

        for interval in range(length - 1, -1, -1):
            for i in range(length - interval):
                if hashmap[i][i + interval]:
                    return s[i : i + interval+1]
def main():
    s = 'babad'
    print(Solution().longestPalindrome(s))

if __name__ == "__main__":
    main()