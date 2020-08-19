from collections import Counter
class Solution:
    def isPossible(self, nums: list) -> bool:
        c = Counter(nums)
        tail = Counter()
        for x in nums:
            if c[x] == 0:
                continue
            elif tail[x] > 0:
                c[x] -= 1
                tail[x] -= 1
                tail[x+1] += 1
            elif all((c[idx] >= 1 for idx in range(x, x+3))):
                for idx in range(x, x+3):
                    c[idx] -= 1
                tail[x+3] += 1
            else:
                return False
        return True
