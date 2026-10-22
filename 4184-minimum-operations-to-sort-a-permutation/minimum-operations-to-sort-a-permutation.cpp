#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        // Helper function to check if an array is a rotation of a target template
        auto get_rotation_shift = [&](const std::vector<int>& arr, const std::vector<int>& target) {
            int pos = -1;
            for (int i = 0; i < n; ++i) {
                if (arr[i] == target[0]) {
                    pos = i;
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (arr[(pos + i) % n] != target[i]) return -1;
            }
            return pos;
        };

        std::vector<int> inc(n), dec(n);
        std::iota(inc.begin(), inc.end(), 0);
        for (int i = 0; i < n; ++i) dec[i] = n - 1 - i;

        int ans = 1e9;

        // Case 1: Check if nums is a rotation of increasing order
        int shift_inc = get_rotation_shift(nums, inc);
        if (shift_inc != -1) {
            // Option A: Just rotate left shift_inc times
            ans = std::min(ans, shift_inc);
            // Option B: Reverse -> Rotate -> Reverse
            // Reverse takes 1 op, shifting (n - shift_inc) % n takes that many, another reverse takes 1 op.
            int alt = 1 + ((n - shift_inc) % n) + 1;
            ans = std::min(ans, alt);
        }

        // Case 2: Check if nums is a rotation of decreasing order
        int shift_dec = get_rotation_shift(nums, dec);
        if (shift_dec != -1) {
            // Option A: Reverse first (1 op), then rotate
            int cost1 = 1 + ((n - shift_dec) % n);
            ans = std::min(ans, cost1);
            
            // Option B: Rotate first, then reverse
            int cost2 = shift_dec + 1;
            ans = std::min(ans, cost2);
        }

        return ans == 1e9 ? -1 : ans;
    }
};