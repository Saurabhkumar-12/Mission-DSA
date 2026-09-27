class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> openBracketIndices;
        string res = "";

        for (char c : s) {
            if (c == '(') {
                openBracketIndices.push_back(res.length());
            } else if (c == ')') {
                int start = openBracketIndices.back();
                openBracketIndices.pop_back();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }

        return res;
    }
};