class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        pre = nums[0]
        idx = 2
        while idx < len(nums):
            if nums[idx] == pre and nums[idx-1] == pre:
                idx_temp = idx + 1
                n = len(nums)
                while idx_temp < n and nums[idx_temp] == pre:
                    idx_temp += 1
                del nums[idx:idx_temp]
            else:
                idx += 1
                pre = nums[idx-2]
        return len(nums)