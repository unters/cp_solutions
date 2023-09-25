#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        if (a[0] == a[n - 1])
            cout << "-1\n";
        
        else {
            int shift = 1;
            while(a[n - shift] == a[n - shift - 1])
                ++shift;

            cout << n - shift << " " << shift << "\n";
            for (int i = 0; i < n - shift; ++i)
                cout << a[i] << " ";
            cout << "\n";

            for (int i = n - shift; i < n; ++i)
                cout << a[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}
