class Solution:
    
    def minEatingSpeed(self, piles: List[int], H: int) -> int:

        def calculate(piles, K, H):
            h = 0
            for pile in piles:
                h += (pile + K - 1) // K
            return h <= H

        lo, hi = 0, max(piles)
        mid = (lo + hi) >> 1
        while lo < mid:
            if calculate(piles=piles, K=mid, H=H):
                hi = mid
            else:
                lo = mid
            mid = (lo + hi) >> 1
        return hi
