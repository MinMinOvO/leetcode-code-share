import math
class Solution:
    def numPrimeArrangements(self, n: int) -> int:

        def is_prime(n: int):
            if n == 1:
                return False
            if n in (2, 3):
                return True
            if n % 6 not in (1, 5):
                return False
            s = int(math.sqrt(n))
            for i in range(5, s+1, 6):
                if n % i == 0 or n % (i+2) == 0:
                    return False
            return True

        cnt_prime = sum(bool(is_prime(val)) for val in  range(1, n+1))
        cnt_composite = n - cnt_prime
        MODEL = 10**9 + 7
        ans = (math.factorial(cnt_prime)%MODEL * math.factorial(cnt_composite)%MODEL)
        ans %= MODEL
        return ans

