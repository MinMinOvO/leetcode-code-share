class Solution:
    def projectionArea(self, grid: list) -> int:
        top = sum(sum((bool(num) for num in arr)) for arr in grid)
        side = 0
        front = 0

        for arr in grid:
            val_max = max(arr)
            side += val_max

        N = len(grid)
        for idx_col in range(N):
            val_max = max(grid[i][idx_col] for i in range(N))
            front += val_max

        return top + side + front

