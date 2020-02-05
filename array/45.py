from typing import List
# 逆向超时了，所以正向贪心
# class Solution:
#     def jump(self, nums: List[int]) -> int:
#         if len(nums) == 1: return 0
#         if len(nums) == 2: return 1
#         max_int = 2 ** 31 - 1
#         max_steps = [max_int for _ in range(len(nums))]
#         idx = len(nums) - 1
#         max_steps[idx] = 0
#         idx -= 1
#         while idx >= 0:
#             max_target = nums[idx]
#             temp_idx = idx + 1
#             min_bound = min(temp_idx + max_target, len(nums))
#             while temp_idx < min_bound:
#                 if max_steps[temp_idx] + 1 < max_steps[idx]:
#                     max_steps[idx] = max_steps[temp_idx] + 1
#                 temp_idx += 1
#             idx -= 1
#         return max_steps[0]

class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) in [0, 1]: return 0
        max_int = 2 ** 31 - 1
        min_steps = [max_int for _ in range(len(nums))]
        min_steps[0] = 0
        idx = 0
        add = 0
        while min_steps[-1] == max_int:
            bound = min(idx + nums[idx] + 1, len(nums))
            temp_idx = idx  + add
            while temp_idx < bound:
                if min_steps[temp_idx] > min_steps[idx] + 1:
                    min_steps[temp_idx] = min_steps[idx] + 1
                temp_idx += 1
            add = nums[idx]
            idx += 1
        return min_steps[-1]


def main():
    temp = [2,3,1,1,4]
    print(Solution().jump(temp))

if __name__ == "__main__":
    main()