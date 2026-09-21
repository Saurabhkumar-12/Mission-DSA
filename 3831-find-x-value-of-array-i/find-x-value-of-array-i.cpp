class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);

            int rem = num % k;

            // Subarray containing only nums[i]
            curr[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                curr[newRem] += dp[r];
            }

            dp = curr;

            // All subarrays ending at current index
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};