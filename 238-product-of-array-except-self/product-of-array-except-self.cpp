class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);

        int left = 1;

        // Left product
        for (int i = 0; i < n; i++) {
            a[i] = left;
            left *= nums[i];
        }

        int right = 1;

        // Right product
        for (int i = n - 1; i >= 0; i--) {
            a[i] *= right;
            right *= nums[i];
        }

        return a;
    }
};