# from Clock import Clock

# clock = Clock()


class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        # clock.time()
        numrows = len(grid)

        # prevent [], none
        if not numrows:
            return 0

        queue = []
        used = []
        num_island = 0

        numcols = len(grid[0])
        # clock.time()
        # clock.time()

        grid_fill0 = [['0' for _ in range(numcols + 2)]
                      for _ in range(numrows + 2)]
        # clock.time()
        # clock.time()

        for row in range(numrows):
            grid_fill0[row + 1][1: numcols + 1] = grid[row]
        # clock.time()
        # clock.time()

        # 1-d list
        if not isinstance(grid[0], list):
            numcols = numrows
            numrows = 1

            grid_fill0 = [['0' for _ in range(numcols + 2)]
                          for _ in range(numrows + 2)]

            grid_fill0[1][1: numcols + 1] = grid

        gen = ((x, y) for x in range(1, numrows + 1)
               for y in range(1, numcols + 1))
        # clock.time()
        # clock.time()

        for x, y in gen:
            if (grid_fill0[x][y] == '1') and ((x, y) not in used):
                queue.append((x, y))
                used.append((x, y))

                num_island += 1

                while (queue):
                    size = len(queue)

                    for _ in range(size):
                        cur_x, cur_y = queue[0]

                        for (next_x, next_y) in ((cur_x - 1, cur_y), (cur_x + 1, cur_y), (cur_x, cur_y - 1), (cur_x, cur_y + 1)):
                            if grid_fill0[next_x][next_y] == '1' and ((next_x, next_y) not in used):
                                queue.append((next_x, next_y))

                            used.append((next_x, next_y))

                        queue.pop(0)
        # clock.time()

        return num_island


sol = Solution()
sol.numIslands([["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], [
               "1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]])
# sol.numIslands([])
# sol.numIslands([["1", "1", "1"], ["0", "1", "0"], ["1", "1", "1"]])
# sol.numIslands(["0", "0", "0", "0", "0"])
# sol.numIslands(["0", "0", "0", "0", "0"])
sol.numIslands(["0", "0", "0", "0", "0"])
