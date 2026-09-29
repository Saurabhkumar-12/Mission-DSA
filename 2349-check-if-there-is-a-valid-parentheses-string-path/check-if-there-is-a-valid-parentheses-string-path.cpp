class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // First cell must be '('
        if (grid[0][0] == ')')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(m + n, false)
            )
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance < m + n; balance++) {

                    if (grid[i][j] == '(') {
                        if (balance > 0) {
                            if (i > 0)
                                dp[i][j][balance] =
                                    dp[i][j][balance] ||
                                    dp[i - 1][j][balance - 1];

                            if (j > 0)
                                dp[i][j][balance] =
                                    dp[i][j][balance] ||
                                    dp[i][j - 1][balance - 1];
                        }
                    }
                    else {
                        if (i > 0)
                            dp[i][j][balance] =
                                dp[i][j][balance] ||
                                dp[i - 1][j][balance + 1];

                        if (j > 0)
                            dp[i][j][balance] =
                                dp[i][j][balance] ||
                                dp[i][j - 1][balance + 1];
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};