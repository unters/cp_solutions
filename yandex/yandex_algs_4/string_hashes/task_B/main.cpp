#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> z_function(string const & s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 1;
    for (int i = 1; i < n; ++i) {
        if (i < r) 
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];
    }

    return z;
}

int main(void) {
    string s;
    cin >> s;

    auto z = z_function(s);
    for (int i = 0; i <= s.size(); ++i) {
        if (i + z[i] == s.size() || i == s.size()) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
