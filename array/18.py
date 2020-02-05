from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4: return []
        nums.sort()
        x = 0
        ret = []
        while x <= len(nums) - 4:
            while x > 0 and x <= len(nums) - 4 and nums[x] == nums[x - 1]:
                x += 1
                continue
            y = x + 1
            while y <= len(nums) - 3:
                while y > x + 1 and y <= len(nums) - 3 and nums[y] == nums[y - 1]:
                    y += 1
                low = y + 1
                high = len(nums) - 1
                while low < high:
                    sum_ = nums[x] + nums[y] + nums[low] + nums[high]
                    if sum_ > target:
                        high -= 1
                        while low < high and nums[high] == nums[high + 1]:
                            high -= 1
                    elif sum_ < target:
                        low += 1
                        while low < high and nums[low] == nums[low - 1]:
                            low += 1
                    else:
                        ret.append([nums[x], nums[y], nums[low], nums[high]])
                        high -= 1
                        low += 1
                        while low < high and nums[high] == nums[high + 1]:
                            high -= 1
                        while low < high and nums[low] == nums[low - 1]:
                            low += 1
                    
                y += 1
            x += 1
        return ret


def main():
    nums = [1,-2,-5,-4,-3,3,3,5]
    target = -11
    print(Solution().fourSum(nums, target))

if __name__ == "__main__":
    main()