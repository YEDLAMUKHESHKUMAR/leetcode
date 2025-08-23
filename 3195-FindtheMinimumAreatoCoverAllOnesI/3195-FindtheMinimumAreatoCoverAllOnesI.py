# Last updated: 8/23/2025, 10:18:48 AM
class Solution(object):
    def minimumArea(self, grid):
        n = len(grid)
        m = len(grid[0])
        minRow, maxRow, minCol, maxCol = n, 0, m, 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    minRow = min(minRow, i)
                    minCol = min(minCol, j)
                    maxRow = max(maxRow, i)
                    maxCol = max(maxCol, j)
        return (maxRow - minRow + 1) * (maxCol - minCol + 1) 

        