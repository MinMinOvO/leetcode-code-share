class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        if n == 0: return 0
        # time & position
        l = [(position[i], ((target-position[i])/speed[i])) for i in range(n)]
        l.sort()
        num = 1
        head = l[-1][1]
        for i in range(len(l)-2, -1, -1):
            if head < l[i][1]:
                num += 1
                head = l[i][1]
        return num