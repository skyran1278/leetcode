from collections import defaultdict
from collections import deque
from typing import List


class Solution1:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        island = 0

        def dfs(i, j):
            if i in (-1, m) or j in (-1, n):
                return False

            if grid[i][j] == 1:
                return True

            grid[i][j] = 1

            right = dfs(i, j + 1)
            bottom = dfs(i + 1, j)
            left = dfs(i, j - 1)
            top = dfs(i - 1, j)

            return bottom and top and right and left

        def bfs(i, j):
            flag = True
            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

            queue = deque()
            queue.append((i, j))
            grid[i][j] = 1

            while queue:
                cur_i, cur_j = queue.popleft()
                for di, dj in directions:
                    next_i = di + cur_i
                    next_j = dj + cur_j

                    if next_i < 0 or next_i >= m or next_j < 0 or next_j >= n:
                        flag = False
                        continue

                    if grid[next_i][next_j] == 0:
                        queue.append((next_i, next_j))
                        grid[next_i][next_j] = 1

            return flag

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and dfs(i, j):
                    island += 1

        return island


class Solution2:
    def closedIsland(self, grid: List[List[int]]) -> int:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        m = len(grid)
        n = len(grid[0])

        island = 0

        def fill(i, j):
            if i in (-1, m) or j in (-1, n) or grid[i][j] == 1:
                return

            grid[i][j] = 1
            for dx, dy in directions:
                fill(i + dx, j + dy)

        def dfs(i, j):
            if grid[i][j] == 1:
                return

            grid[i][j] = 1

            dfs(i, j + 1)
            dfs(i + 1, j)
            dfs(i, j - 1)
            dfs(i - 1, j)

        def bfs(i, j):
            queue = deque()
            queue.append((i, j))
            grid[i][j] = 1

            while queue:
                cur_i, cur_j = queue.popleft()
                for di, dj in directions:
                    next_i = di + cur_i
                    next_j = dj + cur_j

                    if grid[next_i][next_j] == 0:
                        queue.append((next_i, next_j))
                        grid[next_i][next_j] = 1

        # 先包起來，這樣只要看到了就可以直接加 1
        for i in range(m):
            for j in [0, n - 1]:
                fill(i, j)

        for i in [0, m - 1]:
            for j in range(n):
                fill(i, j)

        # 開始做事
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    bfs(i, j)
                    island += 1

        return island


class Solution3:
    def closedIsland(self, grid: List[List[int]]) -> int:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        m, n = len(grid), len(grid[0])

        island = 0

        def dfs(i: int, j: int) -> int:
            if i in (-1, m) or j in (-1, n) or grid[i][j] == 1:
                return 0

            grid[i][j] = 1
            for dx, dy in directions:
                dfs(i + dx, j + dy)

            return 1

        def bfs(i, j):
            queue = deque()
            queue.append((i, j))
            grid[i][j] = 1

            while queue:
                cur_i, cur_j = queue.popleft()
                for di, dj in directions:
                    next_i = di + cur_i
                    next_j = dj + cur_j

                    if grid[next_i][next_j] == 0:
                        queue.append((next_i, next_j))
                        grid[next_i][next_j] = 1

        # 先包起來，這樣只要看到了就可以直接加 1
        for i in range(m):
            for j in range(n):
                if (i in (-1, m) or j in (-1, n)) and grid[i][j] == 0:
                    dfs(i, j)

        # 開始做事
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    island += dfs(i, j)

        return island
