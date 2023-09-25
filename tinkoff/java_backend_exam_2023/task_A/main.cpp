#include <iostream>
using namespace std;


int main(void) {
    int s, n;
    cin >> s >> n;

    int c = (1 + s) * s / 2;
    n -= (n / c) * c;

    int l = 1, r = s;
    while(l != r) {
        int m = (l + r + 1) / 2;

        int p = (m + s) * (s - m + 1) / 2;
        if (n - p >= 0)
            r = m - 1;
        else
            l = m;
    }

    int answer = (l == s)
        ? n
        : n - (l + 1 + s) * (s - l) / 2;
    cout << answer << "\n";

    return 0;
}
