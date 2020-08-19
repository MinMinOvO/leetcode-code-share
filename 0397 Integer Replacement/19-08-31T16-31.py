class Solution:
    def integerReplacement(self, n: int) -> int:
        def hhh(n: int):
            if n == 1:
                return 0
            if n & 1:
                return min(hhh(n=n+1), hhh(n=n-1)) + 1
            else:
                return hhh(n=n>>1) + 1
        return hhh(n=n)
