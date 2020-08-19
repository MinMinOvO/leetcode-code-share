class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        N = len(A)
        mydict = {}
        for num_a, num_b in zip(A, B):
            if num_a == num_b:
                if num_a in mydict:
                    mydict[num_a][2] += 1
                else:
                    mydict[num_a] = [0, 0, 1]
            else:
                if num_a in mydict:
                    mydict[num_a][0] += 1
                else:
                    mydict[num_a] = [1, 0, 0]
                if num_b in mydict:
                    mydict[num_b][1] += 1
                else:
                    mydict[num_b] = [0, 1, 0]
        for arr in mydict.values():
            if sum(arr) == N:
                return min(arr[0:2])

        return -1