#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        unordered_map<int, int> mp;
        int b_size = (n * (n - 1)) / 2;
        for (int j = 0; j < b_size; ++j) {
            int b;
            cin >> b;
            
            if (mp.find(b) == mp.end())
                mp[b] = 1;
            else
                mp[b] += 1;
        }

        set<int> values;
        for (auto & kv : mp)
            values.insert(kv.first);

        vector<int> b;
        for (auto value : values) {
            int count = mp[value];
            while(count > 0) {
                b.push_back(value);
                --count;
            }
        }

        for (int j = 0, k = 0; j < n - 1; ++j) {
            int a = b[k];
            cout << a << " ";
            k += n - 1 - j;
 
            if (j == n - 2)
                cout << a << "\n";
        }
    }

    return 0;
}