class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [int(digit) for digit in str(num)]
        arr = [None for _ in range(10)]
        idx = 0
        for digit in digits:
            if arr[digit] is None or arr[digit] < idx:
                arr[digit] = idx
            idx += 1
        for idx in range(len(digits)):
            for i in range(9, digits[idx], -1):
                if arr[i] is not None and arr[i] > idx:
                    digits[idx] = digits[arr[i]] ^ digits[idx]
                    digits[arr[i]] = digits[arr[i]] ^ digits[idx]
                    digits[idx] = digits[arr[i]] ^ digits[idx]
                    break
            else:
                continue
            break
        return sum([digits[i]*(10**(len(digits)-1-i)) for i in range(len(digits)-1, -1, -1)])