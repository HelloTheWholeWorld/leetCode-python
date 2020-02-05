from typing import List, Optional
class Solution:
    def twoSum(self, nums: List[int], target: int) -> Optional[List[int]]:
        res_table = {value : index for index, value in enumerate(nums)}
        for i, value in enumerate(nums):
            if target-value in res_table and i != res_table[target-value]:
                return [i, res_table[target-value]]
        return None

def main():
    a = [3,2,4]
    target = 6
    temp = Solution()
    print(temp.twoSum(a, target))

if __name__ == '__main__':
    main()
