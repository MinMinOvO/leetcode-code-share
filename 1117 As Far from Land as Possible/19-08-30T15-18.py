class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        que = collections.deque()
        dis = [[0 for _ in range(N)] for _ in range(N)]
        for y, arr in enumerate(grid):
            for x, val in enumerate(arr):
                if val:
                    que.append((y, x))
                    dis[y][x] = 1
        if not que or len(que) == N*N:
            return -1
        while que:
            y, x = que.popleft()
            for y_new, x_new in ((y+1, x), (y-1, x), (y, x+1), (y, x-1)):
                if 0 <= y_new < N and 0 <= x_new < N and not dis[y_new][x_new]:
                    que.append((y_new, x_new))
                    dis[y_new][x_new] = dis[y][x] + 1
        return dis[y][x] - 1
            