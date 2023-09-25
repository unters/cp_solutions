#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


int main(void) {
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    
    /* o stands for "order", c - for "equivalency class".  */
    vector<int> o(n), c(n);

    // k == 0
    {
        vector<pair<char, int>> initial(n);
        for (int i = 0; i < n; ++i)
            initial[i] = { s[i], i };
        sort(initial.begin(), initial.end());

        for (int i = 0; i < n; ++i)
            o[i] = initial[i].second;

        c[o[0]] = 0;
        for (int i = 1; i < n; ++i) {
            c[o[i]] = c[o[i - 1]];
            if (initial[i].first != initial[i - 1].first)
                ++c[o[i]];
        }
    }
    
    int k = 0;
    while ((1 << k) < n) {
        // k -> k + 1
        vector<pair<pair<int, int>, int>> initial(n);
        for (int i = 0; i < n; ++i) 
            initial[i] = { { c[i], c[(i + (1 << k)) % n]}, i };
        sort(initial.begin(), initial.end());

        for (int i = 0; i < n; ++i)
            o[i] = initial[i].second;
        c[o[0]] = 0;
        for (int i = 1; i < n; ++i) {
            c[o[i]] = c[o[i - 1]];
            if (initial[i].first != initial[i - 1].first) 
                ++c[o[i]];
        }

        ++k;
    }

    for (int i = 0; i < n; ++i)
        cout << o[i] << " ";
    cout << "\n";

    return 0;
}
