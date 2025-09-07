#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string solve(int n) {
    if (n == 0) return "0"; 

    vector<bool> visited(n, false);
    queue<string> q;

    q.push("9");

    while (!q.empty()) {
        string s = q.front();
        q.pop();

        
        long long rem = 0;
        for (char c : s) {
            rem = (rem * 10 + (c - '0')) % n;
        }

        if (rem == 0) {
            return s;
        }

        if (!visited[rem]) {
            visited[rem] = true;
            q.push(s + "0");
            q.push(s + "9");
        }
    }

    return ""; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
