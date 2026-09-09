class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000; // 10^3

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            // Prevent potential integer overflow when multiplying by 1000
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return totalCommas;
    }
};