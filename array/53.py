from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 首先是O(n)级别的，这个是动态规划，贪心的话每个保存的是已经走过的最大和？
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        min_num = - (2 ** 31)
        record = [min_num for _ in range(len(nums))]
        record[0] = nums[0]
        for i in range(1, len(nums)):
            record[i] = max(nums[i], nums[i] + record[i - 1])
        return max(record)

def main():
    temp = [-2,1,-3,4,-1,2,1,-5,4]
    print(Solution().maxSubArray(temp))

if __name__ == "__main__":
    main()