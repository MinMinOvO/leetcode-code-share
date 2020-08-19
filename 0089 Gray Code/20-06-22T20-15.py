class Solution:
    
    def grayCode(self, n: int) -> List[int]:
        exist = [-1 for i in range(n)]
        ans = [0]
        t = 0
        c = 0
        while True:
            i = sum(1 for _ in takewhile(lambda x: c & (1 << x), range(n)))
            if i == n:
                break
            exist[i] = -exist[i]
            t += exist[i] * (1 << i)
            ans.append(t)
            c += 1
        return ans