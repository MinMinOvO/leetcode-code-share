class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        elif n <= 2:
            return 1
        a, b, c = 0, 1, 1
        i = 2
        while i < n:
            a = a + b + c
            i += 1
            if i >= n:
                break
            b = a + b + c
            i += 1
            if i >= n:
                break
            c = a + b + c
            i += 1
        return a if n % 3 == 0 else b if n % 3 == 1 else c