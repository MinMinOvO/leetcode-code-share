from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        C, R = len(grid), len(grid[0])
        flag = [[grid[i][j]==1 for j in range(R)] for i in range(C)]
        minute = 0
        que = deque([])
        t = 0
        for i in range(C):
            for j in range(R):
                if grid[i][j] == 2:
                    que.append((i, j, 0))
        while len(que) > 0:
            i, j, t = que.popleft()
            if i >= 1 and flag[i-1][j]:
                flag[i-1][j] = False
                que.append((i-1, j, t+1))
            if i <= C-2 and flag[i+1][j]:
                flag[i+1][j] = False
                que.append((i+1, j, t+1))
            if j >= 1 and flag[i][j-1]:
                flag[i][j-1] = False
                que.append((i, j-1, t+1))
            if j <= R-2 and flag[i][j+1]:
                flag[i][j+1] = False
                que.append((i, j+1, t+1))
        for i in range(C):
            for j in range(R):
                if flag[i][j]:
                    return -1
        return t