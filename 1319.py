from typing import List

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1:
            return -1
        search_set = [i for i in range(n)]

        def find(i):
            raw_i = i
            while search_set[i] != i:
                i = search_set[i]
            search_set[raw_i] = i 
            return i
        
        def union(i ,j):
            search_set[find(j)] = search_set[find(i)]

        for [i, j] in connections:
            union(i, j)
        trees = set()
        for i in range(n):
            trees.add(find(i))
        return len(trees) - 1

if __name__ == '__main__':
    print(Solution().makeConnected(5, [[0,1],[0,2],[3,4],[2,3]]))

# 以下是官方题解之DFS判断连通分量的个数
# class Solution:
#     def makeConnected(self, n: int, connections: List[List[int]]) -> int:
#         if len(connections) < n - 1:
#             return -1
        
#         edges = collections.defaultdict(list)
#         for x, y in connections:
#             edges[x].append(y)
#             edges[y].append(x)
        
#         seen = set()

#         def dfs(u: int):
#             seen.add(u)
#             for v in edges[u]:
#                 if v not in seen:
#                     dfs(v)
        
#         ans = 0
#         for i in range(n):
#             if i not in seen:
#                 dfs(i)
#                 ans += 1
        
#         return ans - 1