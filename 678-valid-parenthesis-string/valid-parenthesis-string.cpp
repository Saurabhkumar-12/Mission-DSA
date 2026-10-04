class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // Minimum open parentheses needed
        int high = 0;  // Maximum open parentheses possible

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // If high < 0, too many ')' brackets
            if (high < 0) return false;

            // Balance cannot be negative
            if (low < 0) low = 0;
        }

        return low == 0;
    }
};