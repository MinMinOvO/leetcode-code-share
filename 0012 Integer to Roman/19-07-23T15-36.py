class Solution:
    def intToRoman(self, num: int) -> str:
        def digit_to_roman(digit, chr_high, chr_mid, chr_low):
            result = []
            if digit >= 5:
                if digit == 9:
                    result.append(chr_low)
                    result.append(chr_high)
                else:
                    result.append(chr_mid)
                    for _ in range(5, digit):
                        result.append(chr_low)
            else:
                if digit == 4:
                    result.append(chr_low)
                    result.append(chr_mid)
                else:
                    for _ in range(digit):
                        result.append(chr_low)
            return result
        result = digit_to_roman(num // 1000, '', '', 'M')
        result.extend(digit_to_roman((num // 100)%10, 'M', 'D', 'C'))
        result.extend(digit_to_roman((num // 10)%10, 'C', 'L', 'X'))
        result.extend(digit_to_roman(num % 10, 'X', 'V', 'I'))
        return ''.join(result)