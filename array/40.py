from typing import List
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0 or target <= 0: return []
        # 回溯算法
        candidates.sort()
        ret = []
        self.lookBack(ret, candidates, target, [], 0)
        return ret

    def lookBack(self, ret, candidates, target, path, start_idx):
        if target == 0:
            ret.append(path)
            return
        i = start_idx
        while i < len(candidates):
            if i > start_idx and candidates[i - 1] == candidates[i]:
                i += 1
                continue
            candidate = candidates[i]
            if target - candidate >= 0:
                self.lookBack(ret, candidates, target-candidate, path + [candidate], i + 1)
            i += 1

def main():
    candidates = [10,1,2, 2,2,  7,6,5]
    target = 6
    print(Solution().combinationSum2(candidates, target))

if __name__ == "__main__":
    main()