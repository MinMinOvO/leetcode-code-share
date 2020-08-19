class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        idx_odd = []
        idx_even = []
        cmp = 0
        for i, n in enumerate(A):
            if n%2 != cmp:
                if cmp:
                    idx_odd.append(i)
                else:
                    idx_even.append(i)
            cmp = 1 - cmp
        assert len(idx_odd) == len(idx_even)
        for a, b in zip(idx_odd, idx_even):
            A[a], A[b] = A[b], A[a]
        return A