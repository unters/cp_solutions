#include <iostream>
#include <vector>
#include <string>
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
        
        if (a[0] != n) {
            cout << "NO\n";
            continue;
        }

        vector<int> b(n);
        int index = n - 1;
        b[index] = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] - a[i] != 0) {
                for (int j = index - 1; j >= index - (a[i - 1] - a[i]); --j)
                    b[j] = b[j + 1];
                index -= a[i - 1] - a[i];
            }

            ++b[index];
        }

        if (index != 0)
            for (int j = index - 1; j >= 0; --j)
                b[j] = b[j + 1];
        
        bool is_symmetrical = true;
        for (int i = 0; i < n; ++i)
            if (a[i] != b[i]) {
                is_symmetrical = false;
                break;
            }

        // for (int i = 0; i < n; ++i)
        //     cout << a[i] << " ";
        // cout << "\n";

        // for (int i = 0; i < n; ++i)
        //     cout << b[i] << " ";
        // cout << "\n";

        string answer = (is_symmetrical == true) ? "YES" : "NO";
        cout << answer << "\n";
    }

    return 0;
}
