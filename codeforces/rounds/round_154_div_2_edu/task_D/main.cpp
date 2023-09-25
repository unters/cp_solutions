#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int solve(vector<int> &);


int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int answer = solve(a);
        cout << answer << "\n";
    }

    return 0;
}


int solve(vector<int> & a) {
    int n = a.size();    
    vector<int> neg_prefix(n);
    vector<int> pos_suffix(n);

    neg_prefix[0] = 1;
    for (int i = 1; i < n; ++i) {
        neg_prefix[i] = neg_prefix[i - 1];
        if (a[i] >= a[i - 1])
            ++neg_prefix[i];
    }

    pos_suffix[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        pos_suffix[i] = pos_suffix[i + 1];
        if (a[i] >= a[i + 1])
            ++pos_suffix[i];
    }

    int operations = min(pos_suffix[0], neg_prefix[n - 1]);
    for (int i = 1; i < n; ++i)
        operations = min(operations, neg_prefix[i - 1] + pos_suffix[i]);
    
    return operations;
}
