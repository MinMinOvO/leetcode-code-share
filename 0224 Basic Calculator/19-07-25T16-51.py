class Solution:
    def calculate(self, s: str) -> int:

        idx = 0
        num = 0
        sign = True
        stack = []

        def get_num():
            nonlocal s, idx
            start = idx
            while idx < len(s) and 48 <= ord(s[idx]) <= 57:
                idx += 1
            return int(s[start:idx])

        def cal(num_o):
            nonlocal num, sign
            if sign:
                num = num + num_o
            else:
                num = num - num_o

        while idx < len(s) and s[idx] == ' ':
            idx += 1
        if idx == len(s):
            return 0
        c = s[idx]
        while idx < len(s):
            if c == '+':
                sign = True
                idx += 1
            elif c == '-':
                sign = False
                idx += 1
            elif c == '(':
                stack.append((num, sign))
                num = 0
                sign = True
                idx += 1
            elif c == ')':
                num_o = num
                num, sign = stack.pop()
                cal(num_o)
                idx += 1
            else:
                cal(get_num())

            while idx < len(s) and s[idx] == ' ':
                idx += 1
            if idx < len(s):
                c = s[idx]
        return num