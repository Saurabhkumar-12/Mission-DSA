#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
long sumXor(long n) {
    if (n == 0) return 1;

    long countZeroBits = 0;
    long temp = n;

    while (temp > 0) {
        if ((temp & 1) == 0) {
            countZeroBits++;
        }
        temp >>= 1;
    }

    return 1L << countZeroBits;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

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
