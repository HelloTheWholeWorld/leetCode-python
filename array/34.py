from typing import List
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l_idx = -1
        r_idx = -1

        l = 0
        r = len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            else:
                l_idx = m if nums[m] == target else l_idx
                r = m - 1
        if l_idx == -1: return [l_idx, r_idx]
        r_idx = l_idx
        while r_idx < len(nums) and nums[r_idx] == target:
            r_idx += 1
        return [l_idx, r_idx - 1]

def main():
    nums = [1]
    target = 1
    print(Solution().searchRange(nums, target))

if __name__ == '__main__':
    main()