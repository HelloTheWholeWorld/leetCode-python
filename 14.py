from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0 or '' in strs: return ''
        max_len = max([len(x) for x in strs])
        index = 0
        while index < max_len:
            temp_lst = [s[0 : index + 1] for s in strs]
            if len(set(temp_lst)) != 1:
                break
            index += 1
        return strs[0][0 : index]

def main():
    temp = ["dog","racecar","car"]
    print(Solution().longestCommonPrefix(temp))

if __name__ == "__main__":
    main()
