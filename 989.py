from typing import List

class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        A.reverse()
        K = list(str(K))
        K.reverse()
        K = [int(x) for x in K]
        max_len = max(len(A), len(K))
        borrow = 0
        i = 0
        while i < max_len or borrow != 0:
            if i >= len(A):
                A.append(0)
            a = A[i]
            b = 0 if i >= len(K) else K[i]
            A[i] = a + b + borrow
            borrow = 0
            if A[i] >= 10:
                A[i] -= 10
                borrow = 1
            i += 1
        A.reverse()
        return A

if __name__ == '__main__':
    print(Solution().addToArrayForm([9,9,9,9,9,9,9,9,9,9], 1))