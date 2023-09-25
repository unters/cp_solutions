#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        k %= 4;
        if (k == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        if (k == 1 || k == 3) 
            for (int i = 1; i <= n; i += 2)
                cout << i << " " << i + 1 << "\n";

        else
            for (int i = 1; i <= n; i += 2)
                if ((i + 1) % 4 == 0)
                    cout << i << " " << i + 1 << "\n";
                else
                    cout << i + 1 << " " << i << "\n";   
    }

    return 0;
}
