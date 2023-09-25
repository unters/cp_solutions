#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        bool a_contains_neg = false, a_contains_pos = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > 0)
                a_contains_pos = true;
            else
                a_contains_neg = true;
        }

        if (!a_contains_neg && !a_contains_pos) {
            cout << "0\n";
            continue;
        }
         
        if (a_contains_pos == false) {
            cout << n - 1 << "\n";
            for (int i = n; i > 1; --i)
                cout << i - 1 << " " << i << "\n";
            continue;
        }

        if (a_contains_neg == false) {
            cout << n - 1 << "\n";
            for (int i = 1; i < n; ++i)
                cout << i + 1 << " " << i << "\n";
            continue;
        }

        int index = 0;
        while(a[index] <= 0) ++index;
        ++index;

        cout << 5 + 2 * (n - 1) << "\n";
        for (int i = 0; i < 5; ++i)
            cout << index << " " << index << "\n";
        
        cout << "2" << " " << index << "\n";
        cout << "2" << " " << index << "\n";
        for (int i = 2; i < n; ++i) {
            cout << i + 1 << " " << i << "\n";
            cout << i + 1 << " " << i << "\n";
        }

    }

    return 0;
}
