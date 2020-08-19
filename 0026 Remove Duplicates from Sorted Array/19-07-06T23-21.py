class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        while i < len(nums):
            j = i - 1
            if nums[j] == nums[i]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)