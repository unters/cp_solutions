#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;


long long solve(vector<pair<int, int>> const &);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> coords(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            coords[i] = { x, y };
        }

        long long answer = solve(coords);
        cout << answer << "\n";
    }

    return 0;
}


long long solve(vector<pair<int, int>> const & coords) {
    int n = coords.size();

    map<int, int> vertical;
    map<int, int> horizontal;
    map<int, int> pos_slope;
    map<int, int> neg_slope;
    for (int i = 0; i < n; ++i) {
        int x = coords[i].first, y = coords[i].second;

        vertical[y] = vertical.find(y) == vertical.end()
            ? 1 : vertical[y] + 1;
        horizontal[x] = horizontal.find(x) == horizontal.end()
            ? 1 : horizontal[x] + 1;

        int pos = x - y;
        pos_slope[pos] = pos_slope.find(pos) == pos_slope.end()
            ? 1 : pos_slope[pos] + 1;
        int neg = x + y;
        neg_slope[neg] = neg_slope.find(neg) == neg_slope.end()
            ? 1 : neg_slope[neg] + 1;
    }

    long long result = 0;
    for (auto & kv : vertical)
        result += 1ll * kv.second * (kv.second - 1);
    
    for (auto & kv : horizontal)
        result += 1ll * kv.second * (kv.second - 1);
        
    for (auto & kv : pos_slope)
        result += 1ll * kv.second * (kv.second - 1);

    for (auto & kv : neg_slope)
        result += 1ll * kv.second * (kv.second - 1);

    return result;
}
