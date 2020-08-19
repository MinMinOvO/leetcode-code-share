class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        r = [0 for _ in range(21)]
        D, M = (0x7fffffff+1) // 3, (0x7fffffff+1) % 3

        def getCublic(num: int):
            a = []
            while num:
                if num < 0:
                    m = num & 0x7fffffff
                    a.append((m % 3 + M) % 3)
                    num = D + (m + M) // 3
                else:
                    a.append(num % 3)
                    num = num // 3
            a += [0 for _ in range(21-len(a))]
            return a

        for num in nums:
            t = getCublic(num)
            for i in range(21):
                r[i] = (r[i] + t[i]) % 3

        num = 0
        while r:
            num = num*3 + r.pop()

        if num > 0x7fffffff:
            num = num - 0x7fffffff - 2 - 0x7fffffff

        return num