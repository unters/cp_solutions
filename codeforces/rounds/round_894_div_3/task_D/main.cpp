#include <iostream>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        long long m = (long long)floor(sqrtl(n * 2)) + 1;
        long long p = m * (m - 1) / 2;
        if (p > n) {
            p = (m - 1) * (m - 2) / 2;
            --m;
        }

        cout << m + (n - p) << "\n";
    }

    return 0;
}
