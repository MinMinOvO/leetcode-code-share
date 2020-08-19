class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        knums = set()
        for num, last_num in zip(nums, list(repeat(None, k)) + nums[:-k]):
            if num in knums:
                return True
            knums.add(num)
            if last_num is not None:
                knums.remove(last_num)
        return False