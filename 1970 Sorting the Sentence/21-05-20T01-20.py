class Solution:
    
    def sortSentence(self, s: str) -> str:
        import re
        words = ['' for _ in range(9)]
        for matchobj in re.findall(r'([a-zA-Z]+)(\d+)', s):
            idx = int(matchobj[1]) - 1
            words[idx] = matchobj[0]
        return ' '.join(words).rstrip(' ')