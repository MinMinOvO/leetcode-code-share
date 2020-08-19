from math import sqrt
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        if len(points) == 1:
            return 1
        N = len(points)
        my_dict_line = {}
        my_dict_x = {}
        my_dict_point = {}
        for i in range(N):
            x, y = points[i][0], points[i][1]
            for j in range(i+1, N):
                dif_x = x - points[j][0]
                dif_y = y - points[j][1]
                if dif_x == 0 and dif_y == 0:
                    if (x, y) in my_dict_point:
                        my_dict_point[(x, y)] += 1
                    else:
                        my_dict_point[(x, y)] = 1
                elif dif_x == 0:
                    if x in my_dict_x:
                        my_dict_x[x] += 1
                    else:
                        my_dict_x[x] = 1
                else:
                    k = dif_y / dif_x
                    b = round(-k*x + y, 6)
                    if (k, b) in my_dict_line:
                        my_dict_line[(k, b)] += 1
                    else:
                        my_dict_line[(k, b)] = 1
        for (x, y), nums in my_dict_point.items():
            if x in my_dict_x:
                my_dict_x[x] += nums
            for (k, b), val in my_dict_line.items():
                if abs(y - k*x - b) < 1e-6:
                    my_dict_line[(k, b)] += nums
        m1 = 1 + int(sqrt(1+8*max(my_dict_line.values()))) >> 1 if my_dict_line else 0
        m2 = 1 + int(sqrt(1+8*max(my_dict_x.values()))) >> 1if my_dict_x else 0
        m3 = 1 + int(sqrt(1+8*max(my_dict_point.values()))) >> 1 if my_dict_point else 0
        return max(m1, m2, m3)