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

        def plus():
            nonlocal sign
            sign = True
        def minus():
            nonlocal sign
            sign = False
        def left():
            nonlocal num, sign, stack
            stack.append((num, sign))
            num = 0
            sign = True
        def right():
            nonlocal num, sign
            num_o, sign = stack.pop()
            if sign:
                num = num_o + num
            else:
                num = num_o - num

        while idx < len(s) and s[idx] == ' ':
            idx += 1
        if idx == len(s):
            return 0
        c = s[idx]
        dic = {
            '+': plus,
            '-': minus,
            '(': left,
            ')': right
        }
        while idx < len(s):
            if c not in dic:
                if sign:
                    num = num + get_num()
                else:
                    num = num - get_num()
            else:
                dic[c]()
                idx += 1
            while idx < len(s) and s[idx] == ' ':
                idx += 1
            if idx < len(s):
                c = s[idx]
        return num