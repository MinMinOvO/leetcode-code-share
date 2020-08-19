class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2):
            str1, str2 = str2, str1
        N1, N2 = len(str1), len(str2)
        while True:
            cnt = str1.count(str2)
            if cnt == 0:
                return ''
            elif cnt * N2 == N1:
                return str2
            else:
                str1, str2 = str2, str1[N2*cnt:],
                N1, N2 = len(str1), len(str2)
