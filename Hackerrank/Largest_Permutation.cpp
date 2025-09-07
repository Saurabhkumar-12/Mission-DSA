#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_map<int, int> pos;  

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 0; i < n && k > 0; i++) {
        int desired = n - i;  
        if (arr[i] == desired) continue;

        int idx = pos[desired];

     
        pos[arr[i]] = idx;
        pos[desired] = i;
        swap(arr[i], arr[idx]);

        k--;
    }

    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
