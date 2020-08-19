class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 1:
            return 0
        dif = nums[0] - nums[1]
        sum_a = dif + 1 if dif >= 0 else 0
        sum_b = 0
        a, b, c, d = 0, 0, nums[0], nums[1]
        i = 1
        for i in range(3, N, 2):
            a, b, c, d = c, d, nums[i - 1], nums[i]
            min_b = min(a, c)
            dif = b - min_b
            if dif >= 0:
                sum_b += dif + 1
            min_c = min(b, d)
            dif = c - min_c
            if dif >= 0:
                sum_a += dif + 1
        i += 2
        a, b, c, d = c, d, nums[-1], 0
        min_b = min(a, c) if i == N else a
        dif = b - min_b
        if dif >= 0:
            sum_b += dif + 1
        if i == N:
            dif = c - b
            if dif >= 0:
                sum_a += dif + 1

        return min(sum_a, sum_b)
    