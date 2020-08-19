from collections import deque


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if len(board) <= 2 or len(board[0]) <= 2: return
        C, R = len(board), len(board[1])
        flag = [[False for _ in range(R)] for _ in range(C)]
        c, r = C - 1, R -1
        que = deque()
        for j in range(1, r):
            if board[0][j] == 'O':
                que.append((0, j))
                flag[0][j] = True
            if board[c][j] == 'O':
                que.append((c, j))
                flag[c][j] = True
        for i in range(1, c):
            if board[i][0] == 'O':
                que.append((i, 0))
                flag[i][0] = True
            if board[i][r] == 'O':
                que.append((i, r))
                flag[i][r] = True
        while que:
            i, j = que.popleft()
            if i >= 1 and board[i-1][j] == 'O' and not flag[i-1][j]:
                que.append((i-1, j))
                flag[i-1][j] = True
            if i < c and board[i+1][j] == 'O' and not flag[i+1][j]:
                que.append((i+1, j))
                flag[i+1][j] = True
            if j >= 1 and board[i][j-1] == 'O' and not flag[i][j-1]:
                que.append((i, j-1))
                flag[i][j-1] = True
            if j < r and board[i][j+1] == 'O' and not flag[i][j+1]:
                que.append((i, j+1))
                flag[i][j+1] = True
        for i in range(1, c):
            for j in range(1, r):
                if board[i][j] == 'O' and not flag[i][j]:
                    board[i][j] = 'X'