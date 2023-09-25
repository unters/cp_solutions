#include <iostream>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        int odd_count = 0;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;

            if (a % 2 == 1)
                ++odd_count;
        }

        if (odd_count % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}