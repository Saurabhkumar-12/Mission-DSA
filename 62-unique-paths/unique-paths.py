class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = {}

        def f(i, j):
            if i == m - 1 and j == n - 1:
                return 1

            if i >= m or j >= n:
                return 0

            if (i, j) in dp:
                return dp[(i, j)]

            dp[(i, j)] = f(i + 1, j) + f(i, j + 1)

            return dp[(i, j)]

        return f(0, 0)