class Solution:
    def isPalindrome(self, s: str) -> bool:
        T = set(string.ascii_letters + string.digits)
        s1 = ''.join(cha for cha in s if cha in T).lower()
        if len(s1) <= 1:
            return True
        return s1[len(s1)//2-1::-1] == s1[(len(s1)+1)//2:]