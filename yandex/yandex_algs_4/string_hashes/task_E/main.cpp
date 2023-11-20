#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> manaker_odd(string const & s);

int main(void) {
    string s;
    cin >> s;

    long long count = 0;
    vector<int> d_odd = manaker_odd(s);
    for (int i = 0; i < d_odd.size(); ++i) {
        count += d_odd[i] + 1;
    }

    string s_even = "#";
    for (char c : s) {
        s_even += c;
        s_even += "#";
    }

    vector<int> d_even = manaker_odd(s_even);
    for (int i = 2; i < d_even.size(); i += 2) {
        count += d_even[i] / 2;
    }

    cout << count << "\n";
    return 0;
}

vector<int> manaker_odd(string const & s) {
    vector<int> d(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i < r)
            d[i] = min(d[l + r - i], r - i);
        while (i - d[i] - 1 >= 0 && i + d[i] + 1 < s.size() && s[i - d[i] - 1] == s[i + d[i] + 1])
            ++d[i];
        if (i + d[i] > r)
            l = i - d[i], r = i + d[i];
    }

    return d;
}
