class Solution:
    
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        
        start = 0
        for index, (number, previous_number) in enumerate(zip(nums[1:], nums[:-1])):
            if number >= previous_number:
                continue
            start = index + 1
            break
        end = start
        print(start)
        for index, (number, previous_number) in enumerate(zip(nums[-1:start-1:-1], nums[-2:start-2 if start-2 >= 0 else None:-1])):
            if number >= previous_number:
                continue
            end = len(nums)-index
            break
        else:
            return 0
        max_num, min_num = max(nums[start-1:end]), min(nums[start-1:end])
        for idx, num in enumerate(nums[:start]):
            if num <= min_num and idx < start:
                continue
            start = idx
            break
        for idx, num in enumerate(nums[-1:end-1:-1]):
            if num >= max_num and len(nums) - idx > end:
                continue
            end = len(nums) - idx
            break
        return end - start