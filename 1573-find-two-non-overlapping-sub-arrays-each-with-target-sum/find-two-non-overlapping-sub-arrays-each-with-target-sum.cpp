class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;
        int best = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;

                // Combine with a previous non-overlapping subarray.
                if (left > 0 && dp[left - 1] != INF) {
                    ans = min(ans, len + dp[left - 1]);
                }

                best = min(best, len);
            }

            dp[right] = best;
        }

        return ans == INF ? -1 : ans;
    }
};