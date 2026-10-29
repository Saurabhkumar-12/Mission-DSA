
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

        return dp[target];
    }
};
