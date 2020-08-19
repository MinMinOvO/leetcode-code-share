class Solution:
    def longestPalindrome(self, s: str) -> int:
        my_dict = dict(zip([chr(i) for i in range(65, 123)], [0 for _ in range(65, 123)]))
        for c in s:
            my_dict[c] += 1
        max_odd = 0
        sum_odd = 0
        for val in my_dict.values():
            if val & 1:
                if val > max_odd:
                    sum_odd += max(max_odd - 1, 0)
                    max_odd = val
                else:
                    sum_odd += val - 1
            else:
                sum_odd += val
        return max_odd + sum_odd