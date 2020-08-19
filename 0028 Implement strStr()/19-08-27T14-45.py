class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        def generateNex(pattern: str) -> list:
            N = len(pattern)
            i, j = -1, 0
            nex = [-1 for _ in range(N)]
            while j < N-1:
                if i == -1 or pattern[i] == pattern[j]:
                    i += 1
                    j += 1
                    nex[j] = i
                else:
                    i = nex[i]
            return nex
        if needle == '':
            return 0
        nex = generateNex(pattern=needle)
        N1, N2 = len(haystack), len(needle)
        i, j = 0, 0
        while i < N1:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == N2:
                    return i - N2
            else:
                j = nex[j]
        return -1