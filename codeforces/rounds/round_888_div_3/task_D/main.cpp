#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


typedef long long ll;


bool solve(vector<ll> &);


int main(void){
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<ll> prefix(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> prefix[i];

        string answer = solve(prefix) ? "YES" : "NO";
        cout << answer << "\n";
    }

    return 0;
}


bool solve(vector<ll> & prefix) {
    int n = prefix.size() + 1;

    ll x = 1ll * n * (n + 1) / 2;
    if (prefix.back() != x) {
        prefix.push_back(x);

        vector<ll> v(n, 0);
        v[0] = prefix[0];
        if (v[0] > n || v[0] < 1)
            return false;

        for (int i = 1; i < prefix.size(); ++i) {
            v[i] = prefix[i] - prefix[i - 1];
            if (v[i] > n || v[0] < 1)
                return false;
        }

        set<ll> s(v.begin(), v.end());
        return s.size() == n;
    }

    vector<ll> v(n - 1, 0);
    v[0] = prefix[0];
    for (int i = 1; i < prefix.size(); ++i)     
        v[i] = prefix[i] - prefix[i - 1];

    // for (int i = 0; i < n; ++i)
    //     if (v[i] > n || v[i] < 1)
    //         return false;

    map<ll, int> mp;
    for (int value : v)
        if (mp.find(value) != mp.end())
            ++mp[value];
        else
            mp[value] = 1;

    vector<ll> buf;
    for (auto & kv : mp)
        if (kv.second > 1)
            buf.push_back(kv.first);
        
    if (buf.size() > 1)
        return false;

    if (buf.size() == 1 && mp[buf[0]] > 2)
        return false;

    vector<ll> zeroes;
    for (ll i = 1; i <= n; ++i)
        if (mp.find(i) == mp.end())
            zeroes.push_back(i);

    return zeroes.size() == 2;    
}
