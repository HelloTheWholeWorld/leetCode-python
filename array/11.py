from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        ans = 0
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans


def main():
    a = [2,3,4,5,18,17,6]
    print(Solution().maxArea(a))

if __name__ == "__main__":
    main()