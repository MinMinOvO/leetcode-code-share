from collections import deque

class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if len(matrix) == 0:
            return []
        C, R = len(matrix[0]), len(matrix)
        if C == 0:
            return [[] for _ in range(R)]
        ans = [[0 for _ in range(C)] for _ in range(R)]
        que = deque()
        vis = [[False for _ in range(C)] for _ in range(R)]
        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    que.append((i, j, 0))
                    vis[i][j] = True
        while que:
            m_y, m_x, m_d = que.popleft()
            for y, x in ((m_y+1, m_x), (m_y-1, m_x), (m_y, m_x+1), (m_y, m_x-1)):
                if 0 <= y < R and 0 <= x < C and not vis[y][x]:
                    vis[y][x] = True
                    d = m_d + 1
                    que.append((y, x, d))
                    ans[y][x] = d
        return ans
            