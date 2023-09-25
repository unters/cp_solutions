#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        vector<int> h(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];

        if (n == 1) {
            cout << (a[0] > k ? 0 : 1) << "\n";
            continue;
        }

        int max_len = a[n - 1] <= k ? 1 : 0;
        int app_cnt = a[n - 1] <= k ? a[n - 1] : 0;
        int l = n - 2, r = a[n - 1] <= k ? n - 1 : n - 2;
        while (l >= 0) {
            // cout << "Debug: " << l << " " << r << " " << max_len << app_cnt << "\n";
            if (h[l] % h[l + 1] != 0) {
                r = l;
                app_cnt = 0;
            }

            app_cnt += a[l];
            if (app_cnt > k)
                while (r > l && app_cnt > k)
                    app_cnt -= a[r--];

            if (l == r && app_cnt > k) {
                app_cnt = 0;
                --r, --l;
            }
            
            else if (app_cnt <= k) {
                max_len = max(max_len, r - l + 1);
                --l;
            }
            // cout << "Debug: " << l << " " << r << " " << max_len << app_cnt << "\n";
            // cout << "Debug: " << (!(l <= 0 && r - n + 1 < max_len)) << "\n";
        }

        cout << max_len << "\n";
    }

    return 0;
}

