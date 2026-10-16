class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtrack(nums, temp, used, ans);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& temp,
                   vector<bool>& used, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, temp, used, ans);

            temp.pop_back();
            used[i] = false;
        }
    }
};