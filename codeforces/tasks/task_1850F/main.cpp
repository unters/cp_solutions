#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int solve(map<int, int> &, int);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a <= n) {
                if (mp.find(a) == mp.end())
                    mp[a] = 1;
                else
                    ++mp[a];
            }
        }

        int answer = solve(mp, n);
        cout << answer << "\n";
    }

    return 0;
}

int solve(map<int, int> & mp, int n) {
    vector<int> cnt(n + 1, 0);
    for (auto & kv : mp) {
        /* value: distance of single jump.
         * count: number of frogs that jump that distance.  */
        int value = kv.first;
        int count = kv.second;

        int distance = value;
        while(distance <= n) {
            cnt[distance] += count;
            distance += value;
        }
    }

    return *max_element(cnt.begin(), cnt.end());
}
