from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        d = defaultdict(list)
        for string in strs:
            key = str(sorted(string))
            d[key].append(string)
        return d.values()