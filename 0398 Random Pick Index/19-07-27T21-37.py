from random import choice
class Solution:

    def __init__(self, nums: List[int]):
        dictionary = {}
        for i in range(len(nums)):
            if dictionary.get(nums[i]) is None:
                dictionary[nums[i]] = [i]
            else:
                dictionary[nums[i]].append(i)
        self.dict = dictionary

    def pick(self, target: int) -> int:
        return choice(self.dict[target])


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)