class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        memo = {}

        def f(i, j):
            if i >= m or j >= n:
                return 0

            
            if obstacleGrid[i][j] == 1:
                return 0

            if i == m - 1 and j == n - 1:
                return 1

            if (i, j) in memo:
                return memo[(i, j)]

            memo[(i, j)] = f(i + 1, j) + f(i, j + 1)

            return memo[(i, j)]

        return f(0, 0)