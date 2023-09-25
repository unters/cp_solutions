#include <iostream>
#include <string>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    string a, b;
    getline(cin, a);
    while(t--) {
        getline(cin, a);
        getline(cin, b);        
        int n = a.size();

        if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
            cout << "NO\n";
            continue;
        }

        bool flag_0 = false, flag_1 = false;
        bool flag_x = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                // cout << i << " : case 1" << "\n";
                flag_x = true;
                continue;
            }

            if (a[i] == b[i] && flag_x == false) {
                // cout << i << " : case 2" << "\n";
                if (a[i] == '0')
                    flag_0 = true;
                else
                    flag_1 = true;
                continue;
            }

            // cout << i << " : case 3" << "\n";
            flag_x = (a[i] == '0' && flag_0) || (a[i] == '1' && flag_1)
                ? false : true;
        }

        string answer = flag_x ? "NO" : "YES";
        cout << answer << "\n";
    }

    return 0;
}
