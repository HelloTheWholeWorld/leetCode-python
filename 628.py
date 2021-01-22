from typing import List
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort() # 从小到大排序
        # 最大的乘积在  最大的三个数， 最小的两个数*最大的三个数 这两个乘积之间产生
        return max(nums[-1] * nums[-2] * nums[-3], nums[-1] * nums[0] * nums[1])

if __name__ == '__main__':
    print(Solution().maximumProduct([5, 1,2,3,4]))