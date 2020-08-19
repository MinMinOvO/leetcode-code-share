class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        hhh = {}
        for dominoe in dominoes:
            if dominoe[0] > dominoe[1]:
                dominoe[0], dominoe[1] = dominoe[1], dominoe[0]
            if hhh.get((dominoe[0], dominoe[1])) is not None:
                hhh[(dominoe[0], dominoe[1])] += 1
            else:
                hhh[(dominoe[0], dominoe[1])] = 1
        num = 0
        for val in hhh.values():
            num += val * (val-1) // 2
        return num