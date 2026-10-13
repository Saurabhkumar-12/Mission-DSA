class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int index = (i + j) % n;

                if (nums[index] > nums[i]) {
                    res[i] = nums[index];
                    break;
                }
            }
        }

        return res;
    }
};