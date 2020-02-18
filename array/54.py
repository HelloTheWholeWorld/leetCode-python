from typing import List
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0: return []
        if len(matrix[0]) == 0: return []
        m = len(matrix) # 行
        n = len(matrix[0]) # 列
        
        dr_val = 0
        decay = [0 , 1, 1, 2]
        decay_base = 0

        ret = []
        i = 0
        j = -1
        while True:
            if dr_val == 0:
                if n - decay[dr_val] - decay_base == 0: return ret
                for _ in range(n - decay[dr_val] - decay_base):
                    j += 1
                    ret.append(matrix[i][j])
                dr_val = 1
            elif dr_val == 1:
                if m - decay[dr_val] - decay_base == 0: return ret
                for _ in range(m - decay[dr_val] - decay_base):
                    i += 1
                    ret.append(matrix[i][j])
                dr_val = 2
            elif dr_val == 2:
                if n - decay[dr_val] - decay_base == 0: return ret
                for _ in range(n - decay[dr_val] - decay_base):
                    j -= 1
                    ret.append(matrix[i][j])
                dr_val = 3
            elif dr_val == 3:
                if m - decay[dr_val] - decay_base == 0: return ret
                for _ in range(m - decay[dr_val] - decay_base):
                    i -= 1
                    ret.append(matrix[i][j])
                dr_val = 0
                decay_base += 2
        
def main():
    matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
    print(Solution().spiralOrder(matrix))

if __name__ == "__main__":
    main()