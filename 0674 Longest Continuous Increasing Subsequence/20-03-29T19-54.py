class Solution:
    
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        iter_nums = iter(nums)
        cnt_max_conSub = 1
        
        num_cur = next(iter_nums)
        while True:
            try:
                cnt_cur_conSub = 1
                num_pre = num_cur
                while (num_cur := next(iter_nums)) > num_pre:
                    num_pre = num_cur
                    cnt_cur_conSub += 1        
                cnt_max_conSub = max(cnt_cur_conSub, cnt_max_conSub)
            except StopIteration:
                cnt_max_conSub = max(cnt_cur_conSub, cnt_max_conSub)
                break
        return cnt_max_conSub