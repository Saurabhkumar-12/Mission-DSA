class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int parts, string current) {
        // We have created 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try 1, 2, or 3 digits for the current part
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Value must be <= 255
            if (stoi(part) > 255)
                continue;

            solve(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "");

        return ans;
    }
};