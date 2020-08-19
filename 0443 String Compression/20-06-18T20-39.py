class Solution:
    def compress(self, chars: List[str]) -> int:
        t = 0
        c = []
        for k, g in groupby(chars):
            l = len(list(g))
            print(k, l)
            if l >= 2:
                c.append(k)
                c += list(str(l))
            else:
                c.append(k)
        chars[:len(c):] = c
        return len(c)