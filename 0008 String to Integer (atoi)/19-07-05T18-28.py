class Solution:
    def myAtoi(self, str: str) -> int:
        idx = 0
        while idx < len(str) and str[idx] == ' ':
            idx = idx + 1
        if idx >= len(str):
            return 0
        if str[idx] == '-':
            sign, idx = -1, idx+1
        elif str[idx] == '+':
            sign, idx = 1, idx+1
        elif ord(str[idx]) >= ord('0') and ord(str[idx]) <= ord('9'):
            sign, idx = 1, idx
        else:
            return 0
        num = 0
        INT_MIN = -(2 ** 31)
        INT_MAX = 2 ** 31 - 1
        if sign < 0:
            def compr(num):
                return num >= INT_MIN
            def changNum(num, dig):
                return num * 10 - dig
        else:
            def compr(num):
                return num <= INT_MAX
            def changNum(num, dig):
                return num * 10 + dig
        while idx < len(str) and ord(str[idx]) >= ord('0') and ord(str[idx]) <= ord('9'):
            num = changNum(num, ord(str[idx]) - ord('0'))
            idx = idx + 1
            if not compr(num):
                return INT_MIN if sign < 0 else INT_MAX
        return num