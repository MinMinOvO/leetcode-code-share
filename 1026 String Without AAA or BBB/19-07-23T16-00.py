class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A < B:
            str_a, str_b = 'b', 'a'
            A, B = B, A
        else:
            str_a, str_b = 'a', 'b'
        l = []
        dif = A - B
        for i in range(B):
            l.append(str_a)
            if i < dif:
                l.append(str_a)
            l.append(str_b)
        for _ in range(B+B, A):
            l.append(str_a)
        return ''.join(l)