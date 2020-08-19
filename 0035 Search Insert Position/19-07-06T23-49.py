class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target <= nums[0]: return 0
        if target == nums[-1]: return len(nums) - 1
        if target > nums[-1]: return len(nums)
        l, r = 0, len(nums)-1
        m = (l + r) // 2
        while l != m:
            if nums[m] < target:
                l = m
            elif nums[m] > target:
                r = m
            else:
                break
            m = (l + r) // 2
        return m if target <= nums[m] else r
        