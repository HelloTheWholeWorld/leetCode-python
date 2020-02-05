from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0: return -1
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = int((low + high) / 2)
            if nums[mid] == target: return mid
            if nums[low] == target: return low
            if nums[high] == target: return high

            if nums[low] < nums[mid]:
                # low 到 mid 有序
                if nums[low] > target or nums[mid] < target:
                    low = mid + 1
                    continue
                else:
                    return self.binarySearch(nums, low, mid, target)
            else:
                #low 到 mid 无序， mid 到 high必定有序
                if nums[mid] > target or nums[high] < target:
                    high = mid - 1
                else:
                    return self.binarySearch(nums, mid, high, target)
        return -1



    def binarySearch(self, nums, low, high, target):
        while low <= high:
            mid = int((low + high) / 2)
            if nums[mid] < target:
                low = mid + 1
            elif nums[mid] > target:
                high = mid - 1
            else:
                return mid
        return -1
        



def main():
    a = [4,5,6,7,0,1,2]
    val = 3
    print(Solution().search(a, val))

if __name__ == "__main__":
    main()