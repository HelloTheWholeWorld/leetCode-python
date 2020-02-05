from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0 or target <= 0: return []
        # 回溯算法
        candidates.sort()
        ret = []
        self.lookBack(ret, candidates, target, [])
        return ret

    def lookBack(self, ret, candidates, target, path):
        if target == 0:
            ret.append(path)
            return
        last = path[-1] if len(path) > 0 else 0
        for candidate in candidates:
            if candidate >= last and target - candidate >= 0:
                self.lookBack(ret, candidates, target-candidate, path + [candidate])

def main():
    candidates = [2,3,5]
    target = 8
    print(Solution().combinationSum(candidates, target))

if __name__ == "__main__":
    main()
