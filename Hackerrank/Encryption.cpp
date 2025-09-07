#include <bits/stdc++.h>

using namespace std;

string encryption(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    int length = s.size();
    int rows = floor(sqrt(length));
    int cols = ceil(sqrt(length));

    if (rows * cols < length) {
        rows++;
    }

    string result;
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < length) {
                result += s[idx];
            }
        }
        if (c != cols - 1) {
            result += ' ';
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
