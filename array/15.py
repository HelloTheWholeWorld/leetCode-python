from typing import List
# 超时了
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         if len(nums) < 3 : return []
#         ret = []
#         for i in range(len(nums)):
#             ret.extend(self.twoSum(nums, i))
#         temp = list(set(ret))
#         return [list(tup) for tup in temp]

#     def twoSum(self, nums, idx_target):
#         ret = []
#         for i in range(len(nums)):
#             for j in range(len(nums)):
#                 if i != j and i != idx_target and j != idx_target and nums[i] + nums[j] + nums[idx_target] == 0:
#                     ret.append(tuple(sorted([nums[i], nums[j], nums[idx_target]])))
#         return ret

# 定一议二，确定最小的
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums = sorted(nums)
        i = 0
        while i <=  len(nums) - 3:
            if nums[i] > 0:
                break
            target = nums[i]
            low = i + 1
            high =  len(nums) - 1
            while low < high:
                if nums[low] + nums[high] + target < 0:
                    low += 1
                    while low < high and nums[low] == nums[low - 1]:
                        low += 1
                elif nums[low] + nums[high] + target == 0:
                    ret.append([target, nums[low], nums[high]])
                    low += 1
                    high -= 1
                    while low < high and nums[low] == nums[low - 1]:
                        low += 1
                    while low < high and nums[high] == nums[high + 1]:
                        high -= 1
                else:
                    high -= 1
                    while low < high and nums[high] == nums[high + 1]:
                        high -= 1
            i += 1
            while i <= len(nums) - 3 and nums[i] == nums[i - 1]:
                i += 1
        return ret


def main():
    nums = [0, 0, 0, 0]
    print(Solution().threeSum(nums))

if __name__ == "__main__":
    main()