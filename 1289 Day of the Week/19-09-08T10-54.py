from datetime import date


class Solution:

    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        day = date(year, month, day)
        name_dict = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                     "Friday", "Saturday"]
        return name_dict[day.isoweekday() % 7]