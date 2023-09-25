#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(void) {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;
        
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            mp[a] = mp.find(a) == mp.end() ? 1 : mp[a] + 1;
        }

        int h = -1;
        int vol = 0;
        int cnt = 0;
        for (auto & kv : mp) {
            int a = kv.first;
            int c = kv.second;

            if (h == -1) {
                h = a;
                cnt = c;
                if (vol + cnt <= x) {
                    vol += cnt;
                    ++h;
                }

                else
                    break;

                continue;
            }

            int d = a - h;
            int m = (x - vol) / cnt;

            vol += min(d, m) * cnt;
            h += min(d, m);
            d = max(0, d - m);
            if (d > 0)
                break;
            
            cnt += c;
            if (vol + cnt <= x) {
                vol += cnt;
                ++h;
            }

            else
                break;
        }

        h += (x - vol) / n;
        cout << h << "\n";
    }

    return 0;
}

