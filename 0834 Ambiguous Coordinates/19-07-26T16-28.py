class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        
        def tostr(i, j, k, S):
            l = list(S)
            if i < j:
                l.insert(i + 1, '.')
                j += 1
                k += 1
            l.insert(j + 1, ', ')
            if k - (1 if i < j else 0) < len(S) - 2:
                l.insert(k + 2, '.')
            return ''.join(l)

        range_upper = 2 if S[1] == '0' else len(S) - 2
        result = []
        if S[len(S) - 2] == '0':
            k = len(S) - 2
            for i in range(1, range_upper):
                for j in range(i, len(S) - 2):
                    if i < j and S[j] == '0':
                        continue
                    if j + 1 < k and S[j+1] == '0':
                        continue
                    result.append(tostr(i, j, k, S))
        else:
            for i in range(1, range_upper):
                for j in range(i, len(S) - 2):
                    if i < j and S[j] == '0':
                        continue
                    for k in range(j + 1, len(S) - 1):
                        if j + 1 < k and S[j+1] == '0':
                            break
                        result.append(tostr(i, j, k, S))
        return result