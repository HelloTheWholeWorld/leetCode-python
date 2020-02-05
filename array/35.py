from typing import List
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0: return 0
        l = 0
        r = len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                return m
        return l

def main():
    nums = [1,3,5,6]
    target = 0
    print(Solution().searchInsert(nums, target))

if __name__ == "__main__":
    main()