class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        if len(barcodes) == 1:
            return [barcodes[0]]
        cnt_nums = {}
        for num in barcodes:
            if num in cnt_nums:
                cnt_nums[num] += 1
            else:
                cnt_nums[num] = 1
        cnt_nums = sorted([(key, val) for key, val in cnt_nums.items()], key=lambda t: t[1])
        dif = cnt_nums[-1][1] - cnt_nums[-2][1] - 1
        num_largest = cnt_nums[-1][0]
        N = len(cnt_nums)
        ans = [num_largest] if dif+1 > 0 else []
        turns = 0
        for i in range(N-1):
            for j in range(cnt_nums[i][1] - turns):
                for k in range(i, N):
                    ans.append(cnt_nums[k][0])
                    if dif > 0 and k < N-2:
                        ans.append(num_largest)
                        dif -= 1
            turns = cnt_nums[i][1]
        return ans