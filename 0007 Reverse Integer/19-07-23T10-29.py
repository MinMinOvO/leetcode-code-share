class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            sign = 0
            x = -x
        else:
            sign = 1
        y = 0
        while x > 0:
            y = y * 10 + x % 10
            if 2147483648 - sign < y:
                return 0
            x = x // 10
        return -y if sign == 0 else y

if __name__ == '__main__':
    print(Solution().reverse(500))