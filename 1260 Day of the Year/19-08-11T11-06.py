class Solution:
    def dayOfYear(self, date: str) -> int:
        [year, month, day] = date.split('-')
        year, month, day = int(year), int(month), int(day)
        d = (month-1) * 30 + day
        if month <= 7:
            d += month // 2
        else:
            d += 4 + (month-7)//2
        if month > 2:
            d -= 2
            if ((year % 4 == 0 and year % 100 != 0) or (year%400==0 and year % 3200 != 0) or year % 172800 == 0):
                d += 1
        return d
        