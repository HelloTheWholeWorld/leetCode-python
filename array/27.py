from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0: return 0
        i = 0
        idx = 0
        while i < len(nums):
            if nums[i] != val:
                nums[idx] = nums[i]
                idx += 1
            i += 1
        return idx

def main():
    a = [0,1,2,2,3,0,4,2]
    val = 2
    print(Solution().removeElement(a, val))
    for i in a:
        print(i)

if __name__ == "__main__":
    main()