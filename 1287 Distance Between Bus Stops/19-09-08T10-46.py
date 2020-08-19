class Solution:

    def distanceBetweenBusStops(self, distance: list,
                                start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination, start
        dis_clockwise = 0
        dis_counterclockwise = 0
        for idx, num in enumerate(distance):
            if start <= idx < destination:
                dis_clockwise += num
            else:
                dis_counterclockwise += num
        return min(dis_clockwise, dis_counterclockwise)
