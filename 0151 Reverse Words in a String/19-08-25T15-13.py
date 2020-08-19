class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        new_words = []
        for word in words:
            if word:
                new_words.append(word)
        new_words.reverse()
        return ' '.join(new_words)