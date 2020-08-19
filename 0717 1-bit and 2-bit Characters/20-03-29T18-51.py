class Solution:

    def isOneBitCharacter(self, bits: List[int]) -> bool:
        iter_bits = iter(bits)
        flag = False
        while True:
            try:
                bit = next(iter_bits)
                if bit == 0:
                    flag = True
                else:
                    bit_2 = next(iter_bits)
                    flag = False
            except StopIteration:
                break
        return flag