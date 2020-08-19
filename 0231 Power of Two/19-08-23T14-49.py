class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        l = n.bit_length()
        cnt = 0
        for i in range(l):
            cnt += (n >> i) & 1
        return cnt == 1