class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE1 = 100019;
        const long long BASE2 = 100043;

        auto check = [&](int len) -> bool {
            unordered_map<long long, int> freq;

            long long h1 = 0, h2 = 0;
            long long p1 = 1, p2 = 1;

            for (int i = 0; i < len; i++) {
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;

                p1 = (p1 * BASE1) % MOD1;
                p2 = (p2 * BASE2) % MOD2;
            }

            freq[h1 * MOD2 + h2]++;

            for (int i = len; i < n; i++) {
                h1 = (h1 * BASE1 + nums[i]
                     - (p1 * nums[i - len]) % MOD1 + MOD1) % MOD1;

                h2 = (h2 * BASE2 + nums[i]
                     - (p2 * nums[i - len]) % MOD2 + MOD2) % MOD2;

                freq[h1 * MOD2 + h2]++;
            }

            for (auto& it : freq) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};