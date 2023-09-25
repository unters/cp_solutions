#include <iostream>
#include <map>
#include <cmath>
using namespace std;


long long solve(map<int, int> &, long long, long long);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        map<int, int> a;
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            if (a.find(value) == a.end())
                a[value] = 1;
            else
                a[value] += 1;
        }

        int q;
        cin >> q;

        for (int j = 0; j < q; ++j) {
            long long x, y;
            cin >> x;
            cin >> y;

            long long answer = solve(a, x, y);
            cout << answer << " ";
        }

        cout << "\n";
    }

    return 0;
}


long long solve(map<int, int> & a, long long b, long long c) {
    long long d = b * b - 4ll * c;

    if (d < 0ll)
        return 0;
    
    else if (d == 0ll) {
        long long x = b / 2;
        if (a.find(x) == a.end())
            return 0;
        return (1ll * a[x] * (a[x] - 1)) / 2;
    }

    else {
        long long x_1 = (b - sqrtl(d)) / 2;
        long long x_2 = (b + sqrtl(d)) / 2;
        if (x_1 + x_2 != b || 1ll * x_1 * x_2 != c)
            return 0;
        if (a.find(x_1) == a.end() || a.find(x_2) == a.end())
            return 0;        
        return 1ll * a[x_1] * a[x_2];
    }
}
