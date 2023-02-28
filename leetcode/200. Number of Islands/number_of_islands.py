from Clock import Clock

clock = Clock()


class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        # prevent [], none
        if not grid:
            return 0

        grid_fill0 = self.fill0(grid)

        num_island = 0
        for row in range(1, len(grid) + 1):
            for col in range(1, len(grid[0]) + 1):

                if grid_fill0[row][col] == '1':
                    self.bfs(grid_fill0, row, col)
                    num_island += 1

        return num_island

    def fill0(self, grid):
        numrows = len(grid)
        numcols = len(grid[0])

        grid_fill0 = [['0' for _ in range(numcols + 2)]
                      for _ in range(numrows + 2)]

        for row in range(numrows):
            grid_fill0[row + 1][1: numcols + 1] = grid[row]

        return grid_fill0

    def bfs(self, grid, row, col):
        queue = []
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        queue.append((row, col))
        grid[row][col] = '#'

        while queue:
            for _ in range(len(queue)):
                cur_row, cur_col = queue[0]

                for dx, dy in directions:
                    next_row, next_col = cur_row + dx, cur_col + dy
                    if grid[next_row][next_col] == '1':
                        queue.append((next_row, next_col))
                        grid[next_row][next_col] = '#'

                queue.pop(0)


sol = Solution()

# sol.numIslands([["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], [
#                "1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]])
# sol.numIslands([])
# sol.numIslands([["1", "1", "1"], ["0", "1", "0"], ["1", "1", "1"]])
# sol.numIslands(["0", "0", "0", "0", "0"])
