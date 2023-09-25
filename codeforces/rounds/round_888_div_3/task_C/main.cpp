#include <iostream>
#include <vector>
#include <string>
using namespace std;


string solve(vector<int> const &, int);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> c(n);
        for (int j = 0; j < n; ++j)
            cin >> c[j];

        string answer = solve(c, k);
        cout << answer << "\n";
    }

    return 0;
}


string solve(vector<int> const & c, int k) {
    int n = c.size();

    if (c[0] == c[n - 1]) {
        int count = 0;
        for (int i = 1; i < n - 1; ++i)
            if (c[i] == c[0])
                ++count;

        return (count >= k - 2) ? "YES" : "NO";
    }

    else {
        int l = 1, r = n - 2;
        int l_count = 0, r_count = 0;
        while(l < r) {
            if (l_count == k - 1 && r_count == k - 1)
                break;

            if (l_count != k - 1 && c[l] == c[0])
                ++l_count;

            if (l_count != k - 1)
                ++l;

            if (r_count != k - 1 && c[r] == c[n - 1])
                ++r_count;

            if (r_count != k - 1)
                --r;
        }

        return (l_count >= k - 1 && r_count >= k - 1) ? "YES" : "NO";
    }
}
