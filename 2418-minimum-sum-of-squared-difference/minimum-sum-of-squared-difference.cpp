#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total_diff = 0;
        int max_d = 0;

        // Find absolute differences and the maximum difference
        std::vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = std::abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
            if (diff[i] > max_d) {
                max_d = diff[i];
            }
        }

        long long k = (long long)k1 + k2;
        if (total_diff <= k) return 0;

        // Count frequencies of each difference
        std::vector<int> count(max_d + 1, 0);
        for (int d : diff) {
            count[d]++;
        }

        // Greedily reduce the largest differences using bucket counts from right to left
        for (int d = max_d; d > 0 && k > 0; --d) {
            if (count[d] == 0) continue;
            
            long long take = std::min((long long)count[d], k);
            count[d] -= take;
            count[d - 1] += take;
            k -= take;
        }

        // Calculate the minimum sum of squared differences
        long long ans = 0;
        for (int d = 1; d <= max_d; ++d) {
            if (count[d] > 0) {
                ans += (long long)count[d] * d * d;
            }
        }

        return ans;
    }
};