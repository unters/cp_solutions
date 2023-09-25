#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) 
        cin >> l[i];

    sort(l.begin(), l.end());
    vector<int> prefix(k + 1, 0), suffix(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        prefix[i] = prefix[i - 1] + (l[i] - l[i - 1]);
        suffix[i] = suffix[i - 1] + (l[n - i] - l[n - i - 1]);
    }

    int max_decr = 0;
    for (int i = 0; i <= k; ++i) {
        int cur_decr = prefix[i] + suffix[k - i];
        max_decr = max(max_decr, cur_decr);
    }

    cout << l[n - 1] - l[0] - max_decr << "\n";
    return 0;
}
