class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 1);

        // Product of elements before i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            a[i] = prefix;
            prefix *= nums[i];
        }

        // Product of elements after i
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            a[i] *= suffix;
            suffix *= nums[i];
        }

        return a;
    }
};