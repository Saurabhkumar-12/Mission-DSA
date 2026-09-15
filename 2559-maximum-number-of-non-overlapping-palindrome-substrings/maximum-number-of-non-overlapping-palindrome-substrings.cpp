class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || isPal[i + 1][j - 1])) {

                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {

            // Option 1: Skip character s[i]
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Option 2: Select a palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (isPal[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};