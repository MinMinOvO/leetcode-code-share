class Solution:
    def isPalindrome(self, x: int) -> bool:
        z = x
        y = 0
        while x > 0:
            y = y * 10 + x % 10
            x //= 10
        return z == y