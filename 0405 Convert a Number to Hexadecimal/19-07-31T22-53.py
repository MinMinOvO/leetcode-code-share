class Solution:
    def toHex(self, num: int) -> str:
        o = []
        mdict = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']
        for _ in range(8):
            o.insert(0, mdict[num & 0x0000000f])
            num = num >> 4
        while len(o) > 1 and o[0] == '0':
            o.pop(0)
        return ''.join(o)
            
            