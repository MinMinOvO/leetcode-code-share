class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        R = [[]]
        for k, g in itertools.groupby(sorted(nums)):
            l = list(g)
            for i in range(len(R)):
                for j in range(1, len(l)+1):
                    R.append(R[i] + l[:j])
        return R