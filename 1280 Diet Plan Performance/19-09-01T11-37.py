class Solution:
    def dietPlanPerformance(self, calories: list, k: int, lower: int, upper: int) -> int:
        N = len(calories)
        t = sum(calories[i] for i in range(k))
        if t > upper:
            point = 1
        elif t < lower:
            point = -1
        else:
            point = 0
        idx = k
        while idx < N:
            t -= calories[idx-k]
            t += calories[idx]
            if t > upper:
                point += 1
            elif t < lower:
                point -= 1
            idx += 1

        return point

