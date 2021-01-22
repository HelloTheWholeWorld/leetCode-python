from typing import List
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ret = []
        if len(s) <= 2:
            return ret
        start = 0
        for i in range(len(s)):
            if i - 1 < 0 or s[i-1] == s[i]:
                continue
            else:
                if i - start >= 3:
                    ret.append([start, i - 1])
                start = i
        if len(s) - start >= 3:
            ret.append([start, len(s) - 1])
        return ret

if __name__ == '__main__':
    print(Solution().largeGroupPositions('aaa'))
