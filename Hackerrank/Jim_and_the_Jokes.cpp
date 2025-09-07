#include <bits/stdc++.h>
using namespace std;

bool isValidBaseAndNumber(int base, const string &num) {
    if (base < 2) return false;
    for (char c : num) {
        int digit = c - '0';
        if (digit >= base) return false;
    }
    return true;
}

long long convertToDecimal(int base, const string &num) {
    long long val = 0;
    for (char c : num) {
        val = val * base + (c - '0');
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, string>> events(n);
    for (int i = 0; i < n; i++) {
        int M; string D;
        cin >> M >> D;
        events[i] = {M, D};
    }

    unordered_map<long long, int> freq;

    for (auto &e : events) {
        int base = e.first;
        string num = e.second;
        if (!isValidBaseAndNumber(base, num)) continue;
        long long val = convertToDecimal(base, num);
        freq[val]++;
    }

    long long jokes = 0;
    for (auto &p : freq) {
        long long c = p.second;
        if (c > 1) {
            jokes += c * (c - 1) / 2;
        }
    }

    cout << jokes << "\n";

    return 0;
}
