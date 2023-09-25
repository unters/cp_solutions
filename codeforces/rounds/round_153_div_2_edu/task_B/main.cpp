#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int m, k, a_1, a_k;
        cin >> m >> k >> a_1 >> a_k;

        int n = m;

        int used_ks = min(a_k, m / k);
        m -= used_ks * k;

        int used_1s = min(a_1, m);
        m -= used_1s;

        int p = m / k;
        int d = m - p * k;
        if (p * k == m)
            cout << p << "\n";

        else if (p * k + k > n)
            cout << p + d << "\n";
        
        else if (p * k + k == n)
            cout << p + 1 << "\n";
        
        else {
            int r = (n - m) % k;
            int l = k - d - r;
            int ones = a_1 > r ? k + r : r;
            int answer = ones >= d + r ? p + 1 : p + d;

            cout << answer << "\n";
        }
    }

    return 0;
}
