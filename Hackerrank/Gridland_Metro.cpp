#include <bits/stdc++.h>
using namespace std;

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    unordered_map<int, vector<pair<int,int>>> tracksMap;
    for (auto &t : track) {
        int r = t[0], c1 = t[1], c2 = t[2];
        tracksMap[r].push_back({c1, c2});
    }
    long long occupied = 0;
    for (auto &entry : tracksMap) {
        auto &intervals = entry.second;
        sort(intervals.begin(), intervals.end());
        int currentStart = intervals[0].first;
        int currentEnd = intervals[0].second;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].first <= currentEnd + 1) {
                if (intervals[i].second > currentEnd) {
                    currentEnd = intervals[i].second;
                }
            } else {
                occupied += (long long)(currentEnd - currentStart + 1);
                currentStart = intervals[i].first;
                currentEnd = intervals[i].second;
            }
        }
        occupied += (long long)(currentEnd - currentStart + 1);
    }
    long long totalCells = (long long)n * m;
    return totalCells - occupied;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> track(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> track[i][0] >> track[i][1] >> track[i][2];
    }

    cout << gridlandMetro(n, m, k, track) << "\n";

    return 0;
}
