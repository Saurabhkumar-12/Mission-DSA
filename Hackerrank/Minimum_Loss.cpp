#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int minimumLoss(vector<long> price) {
    int n = price.size();
    vector<pair<long, int>> pricesWithIndex(n);
    for (int i = 0; i < n; i++) {
        pricesWithIndex[i] = {price[i], i};
    }
    sort(pricesWithIndex.begin(), pricesWithIndex.end());

    long minLoss = LONG_MAX;
    for (int i = 1; i < n; i++) {
        long diff = pricesWithIndex[i].first - pricesWithIndex[i-1].first;
        if (diff > 0 && pricesWithIndex[i].second < pricesWithIndex[i-1].second) {
            if (diff < minLoss) {
                minLoss = diff;
            }
        }
    }
    return (int)minLoss;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split(rtrim(price_temp_temp));

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
