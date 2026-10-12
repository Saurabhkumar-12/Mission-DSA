class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(31, 0);
        for (int x : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((x >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        
        long long total_sum = 0;
        long long MOD = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long current_val = 0;
            for (int i = 0; i <= 30; ++i) {
                if (bit_count[i] > 0) {
                    current_val |= (1LL << i);
                    bit_count[i]--;
                }
            }
            total_sum = (total_sum + (current_val * current_val) % MOD) % MOD;
        }
        
        return total_sum;
    }
};