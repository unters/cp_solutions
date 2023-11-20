#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> manaker_odd(vector<int> const & v);

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[2 * i + 1];
    }

    vector<int> d = manaker_odd(v);
    for (int i = v.size() - 3; i > 0; i -= 2) {
        if (d[i] == i) {
            cout << n - (i / 2) << " ";
        }
    }

    cout << n << "\n";
    return 0;
}

vector<int> manaker_odd(vector<int> const & v) {
    vector<int> d(v.size(), 0);
    int l = 0, r = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i < r)
            d[i] = min(d[l + r - i], r - i);
        while (i - d[i] - 1 >= 0 && i + d[i] + 1 < v.size() && v[i - d[i] - 1] == v[i + d[i] + 1])
            ++d[i];
        if (i + d[i] > r)
            l = i - d[i], r = i + d[i];
    }

    return d;
}
