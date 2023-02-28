from typing import List


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        (x1, y1) = coordinates[0]
        (x2, y2) = coordinates[1]

        # y = mx + b
        if x2 - x1 != 0:
            m = (y2 - y1) / (x2 - x1)
            b = y1 - m * x1
            for (x, y) in coordinates:
                if m * x + b != y:
                    return False
        else:
            m = x1
            for (x, y) in coordinates:
                if x != m:
                    return False
        return True
