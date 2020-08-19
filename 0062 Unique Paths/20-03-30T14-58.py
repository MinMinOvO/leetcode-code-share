import math


class Solution:
    
    def uniquePaths(self, m: int, n: int) -> int:

        def nCr(n, r):
            f = math.factorial
            return f(n) // f(r) // f(n-r)
        if m == 1 or n == 1:
            return 1
        return nCr(m + n - 2, min(m, n)-1)