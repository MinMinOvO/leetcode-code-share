class Solution:
    
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones = sorted(stones)
        n = len(stones)
        max_coverage, distance_max_coverage = 1, 1
        distances = list(map(operator.sub, islice(stones, 1, None), islice(stones, 0, len(stones)-1)))
        distance_sum, distances_cur = 1, deque()
        for i, d in enumerate(distances):
            distances_cur.append(d)
            distance_sum += d
            while distance_sum > n:
                distance_sum -= distances_cur.popleft()
            if len(distances_cur) + 1 > max_coverage:
                max_coverage = len(distances_cur) + 1
                distance_max_coverage = distance_sum
        if distance_max_coverage == max_coverage and n - max_coverage == 1:
            min_step = 2 if distances[-1] >= 3  or distances[0] >= 3 else 1
        else:
            min_step = n - max_coverage
        max_step = sum(distances) - min(distances[0], distances[-1]) - n + 2
        return [min_step, max_step]