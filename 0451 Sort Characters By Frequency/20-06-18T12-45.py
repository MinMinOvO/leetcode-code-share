class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        l = sorted(c.items(), key=lambda x:x[1], reverse=True)
        s = ''.join(k * v for k, v in l)
        return s