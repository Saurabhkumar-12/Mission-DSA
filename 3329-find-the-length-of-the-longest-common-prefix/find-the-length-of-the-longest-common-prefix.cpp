class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        for (int num : arr1) {
            string s = to_string(num);

            for (int i = 1; i <= s.size(); i++) {
                prefixes.insert(s.substr(0, i));
            }
        }

        int ans = 0;

        for (int num : arr2) {
            string s = to_string(num);

            for (int i = 1; i <= s.size(); i++) {
                if (prefixes.count(s.substr(0, i))) {
                    ans = max(ans, i);
                }
            }
        }

        return ans;
    }
};