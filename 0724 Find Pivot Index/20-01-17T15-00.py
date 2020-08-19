class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1
        l = 0
        r = sum(nums) - nums[0]
        for i, (a, b) in enumerate(zip(nums[:-1], nums[1:])):
            if l == r:
                return i
            l += a
            r -= b
        if l == r:
            return i + 1
        return -1