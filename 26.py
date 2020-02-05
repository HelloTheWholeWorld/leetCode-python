from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        temp_set = set()
        i = 0
        idx = 0
        while i < len(nums):
            if nums[i] not in temp_set:
                nums[idx] = nums[i]
                idx += 1
                temp_set.add(nums[i])
            i += 1
        return idx

def main():
    nums = [0,0,1,1,1,2,2,3,3,4]
    print(Solution().removeDuplicates(nums))
    for num in nums:
        print(num)

if __name__ == "__main__":
    main()