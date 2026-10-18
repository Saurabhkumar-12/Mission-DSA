class Solution {
public:
    const int MOD = 1e9 + 7;
    long long comb[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long l = solve(left);
        long long r = solve(right);

        long long ways = comb[n - 1][left.size()];
        ways = ways * l % MOD;
        ways = ways * r % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};