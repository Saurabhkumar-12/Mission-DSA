class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> end(26, 0);

        for (char ch : s) {
            int i = ch - 'a';

            long long total = 1;

            for (int j = 0; j < 26; j++) {
                total = (total + end[j]) % MOD;
            }

            end[i] = total;
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            ans = (ans + end[i]) % MOD;
        }

        return ans;
    }
};