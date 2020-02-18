from typing import List
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # 动态规划，超出时间限制
        # if len(nums) == 0 or len(nums) == 1: return True
        # reach = [False] * len(nums)
        # reach[-1] = True
        # idx = len(nums) - 2
        # while idx >= 0:
        #     bound = min(idx + nums[idx], len(nums) - 1)
        #     temp_idx = bound
        #     while temp_idx > idx:
        #         if reach[temp_idx]:
        #             reach[idx] = True
        #             break
        #         temp_idx -= 1 
        #     idx -= 1
        # return reach[0]

        # 动态规划, 符合时间限制
        if len(nums) in [0, 1]: return True
        last = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] + i >= last:
                last = i
        return last == 0

        # 回溯

def main():
    temp = [3,2,1,1,4]
    print(Solution().canJump(temp))

if __name__ == "__main__":
    main()