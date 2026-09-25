class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int start = 1, end = x;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};