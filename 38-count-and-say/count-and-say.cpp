class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            for (int j = 0; j < s.length(); ) {
                int count = 0;
                char ch = s[j];

                while (j < s.length() && s[j] == ch) {
                    count++;
                    j++;
                }

                temp += to_string(count);
                temp += ch;
            }

            s = temp;
        }

        return s;
    }
};