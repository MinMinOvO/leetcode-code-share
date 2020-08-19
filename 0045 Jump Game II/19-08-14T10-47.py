class Solution:
    def jump(self, nums: list) -> int:
        N = len(nums)
        if N <= 1:
            return 0
        num_step = 0
        n = 0
        while True:
            m = nums[n]
            cnt = 1
            for i in range(n+1, n+nums[n]+1):
                if i == N-1:
                    return num_step+1
                t = nums[i] + cnt
                if t >= m:
                    n = i
                    m = t
                cnt += 1
            num_step += 1