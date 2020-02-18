from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) in [0, 1]: return intervals
        sorted_lst = sorted(intervals, key=lambda x : x[0])
        merged = [sorted_lst[0]]
        for i in range(1, len(intervals)):
            left = merged[-1]
            merged = merged[:-1]
            merged.extend(self.merge_two(left, sorted_lst[i]))
        return merged

    def merge_two(self, temp_left, temp_right):
        if temp_left[1] >= temp_right[0]:
            if temp_left[1] >= temp_right[1]:
                add = [temp_left]
            else:
                add = [[temp_left[0], temp_right[1]]]
        else:
                add = [temp_left, temp_right]
        return add

def main():
    temp = [[1,4], [0,1]]
    print(Solution().merge(temp))

if __name__ == "__main__":
    main()