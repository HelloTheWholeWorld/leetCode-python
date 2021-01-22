from typing import List

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        N = len(edges)
        union_find_set = [i for i in range(N+1)]
        
        def find(i):
            while union_find_set[i] != i:
                i = union_find_set[i]
            return i

        for edge in edges:
            i, j = edge
            i_f, j_f = find(union_find_set[i]), find(union_find_set[j])
            if i_f != j_f:
                union_find_set[j_f] = union_find_set[i_f]
            else:
                return edge

if __name__ == '__main__':
    print(Solution().findRedundantConnection([[3,4],[1,2],[2,4],[3,5],[2,5]]))
