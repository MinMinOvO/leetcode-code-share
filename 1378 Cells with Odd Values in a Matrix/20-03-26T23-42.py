from collections import Counter


class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        cnter_r = Counter(pair[0] for pair in indices)
        cnter_c = Counter(pair[1] for pair in indices)
        cnt_odd_row = sum(cnt % 2 for cnt in cnter_r.values())
        cnt_odd_col = sum(cnt % 2 for cnt in cnter_c.values())
        return m*cnt_odd_row + n*cnt_odd_col - 2 * cnt_odd_row * cnt_odd_col