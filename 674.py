from typing import List

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        max_increase = 1
        i = 1
        now_increase = 1
        while i < len(nums):
            if nums[i] > nums[i-1]:
                now_increase += 1
            else:
                max_increase = max(max_increase, now_increase)
                now_increase = 1
            i += 1
        max_increase = max(max_increase, now_increase)
        return max_increase

if __name__ == '__main__':
    print(Solution().findLengthOfLCIS([2,2,2,2,2]))

        