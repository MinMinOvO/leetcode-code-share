class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0
        width, height = len(grid[0]), len(grid)
        visited = [[False for _ in range(width)] for x in range(height)]
        cnt = 0
        for i in range(height):
            for j in range(width):
                if grid[i][j] == '1' and not visited[i][j]:
                    cnt += 1
                    visited[i][j] = True
                    queue = [(i, j)]
                    while len(queue) > 0:
                        (x, y) = queue.pop(0)
                        if x-1 >= 0 and not visited[x-1][y] and grid[x-1][y]=='1':
                            visited[x - 1][y] = True
                            queue.append((x - 1, y))
                        if x+1 < height and not visited[x+1][y] and grid[x+1][y]=='1':
                            visited[x + 1][y] = True
                            queue.append((x + 1, y))
                        if y-1 >= 0 and not visited[x][y-1] and grid[x][y-1]=='1':
                            visited[x][y-1] = True
                            queue.append((x, y-1))
                        if y+1 < width and not visited[x][y+1] and grid[x][y+1]=='1':
                            visited[x][y+1] = True
                            queue.append((x, y+1))
        return cnt