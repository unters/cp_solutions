#include <iostream>
#include <map>
#include <utility>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int d, s;
            cin >> d >> s;

            if (mp.find(d) == mp.end())
                mp[d] = s;
            else
                mp[d] = min(mp[d], s);
        }

        int k = 1;
        int max_k = (mp.find(1) == mp.end())
            ? INT32_MAX
            : k + mp[1] / 2 - 1 + mp[1] % 2;
        for (auto & kv : mp) {
            int d = kv.first;
            int s = kv.second;
            if (d >= max_k)
                break;
            
            max_k = min(max_k, d + s / 2 - 1 + s % 2);
        }

        cout << max_k << "\n";
    }

    return 0;
}
