string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int left = 0, right = n - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left] > s[right]) {
                s[right] = s[left];
            } else {
                s[left] = s[right];
            }
            changed[left] = changed[right] = true;
            k--;
        }
        left++;
        right--;
    }

    if (k < 0) return "-1";

    left = 0;
    right = n - 1;
    while (left <= right && k > 0) {
        if (left == right) {
            if (s[left] != '9' && k > 0) {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (k >= 1) {
                        s[left] = s[right] = '9';
                        k--;
                    }
                } else {
                    if (k >= 2) {
                        s[left] = s[right] = '9';
                        k -= 2;
                    }
                }
            }
        }
        left++;
        right--;
    }

    return s;
}
