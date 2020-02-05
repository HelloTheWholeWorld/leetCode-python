from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        min_diff = 2 ** 31  - 1
        if len(nums) < 3: return 0
        i = 0
        nums = sorted(nums)
        ret = 0
        while i <= len(nums) - 3:
            if i > 0 and nums[i - 1] == nums[i]:
                i += 1
                continue
            low = i + 1
            high = len(nums) - 1
            base = nums[i]
            while low < high:
                sum_ = base + nums[low] + nums[high]
                if abs(sum_ - target) < min_diff:
                    min_diff = abs(sum_ - target)
                    ret = sum_

                if sum_ < target:
                    low += 1
                    while low < high and nums[low] == nums[low - 1]:
                        low += 1
                elif sum_ == target:
                    return sum_
                else:
                    high -= 1
                    while low < high and nums[high] == nums[high + 1]:
                        high -= 1
            i += 1
        return ret

def main():
    nums = [1, 1, 1, 1]
    target = 0
    print(Solution().threeSumClosest(nums, target))

if __name__ == "__main__":
    main()