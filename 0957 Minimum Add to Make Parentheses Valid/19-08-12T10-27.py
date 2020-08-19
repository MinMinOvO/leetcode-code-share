class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        cnt = 0
        m = 0
        for c in S:
            if c == '(':
                cnt += 1
            else:
                if cnt > 0:
                    cnt -= 1
                else:
                    m += 1
        return cnt + m