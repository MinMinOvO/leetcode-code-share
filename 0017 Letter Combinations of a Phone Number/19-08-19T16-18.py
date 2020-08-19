class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        my_dict = [None, None, 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        ans = [[]]
        for digit in digits:
            s = my_dict[int(digit)]
            cnt = len(s)
            m = []
            for c in s:
                if cnt == 1:
                    for arr in ans:
                        arr.append(c)
                    ans += m
                else:
                    ans_copy = [arr.copy() for arr in ans]
                    for arr in ans_copy:
                        arr.append(c)
                    m += ans_copy
                    cnt -= 1
                    
        return [''.join(arr) for arr in ans]