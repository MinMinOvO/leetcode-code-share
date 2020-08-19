class Solution:
    def countBits(self, num: int) -> List[int]:
        if num == 0:
            return [0]
        result = [0, 1]
        mul = 2
        l = len(result)
        while l <= num:
            if l > mul:
                mul <<= 1
            result.append(result[l-mul]+1)
            l = len(result)
        return result