import itertools
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        nums1 = iter(version1.split('.'))
        nums2 = iter(version2.split('.'))
        mmm = itertools.zip_longest(nums1, nums2, fillvalue='0')
        iterator =((int(str1), int(str2))for str1, str2 in mmm)
        for num1, num2 in iterator:
            if num1 > num2:
                return 1
            elif num1 < num2:
                return -1
        return 0
            
            