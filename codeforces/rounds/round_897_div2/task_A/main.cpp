#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


vector<pair<int, int>> solve(vector<pair<int, int>> &);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
            a[i].first = i;
        }

        auto b = solve(a);
        for (int i = 0; i < n; ++i)
            cout << b[i].second << " ";
        cout << "\n";
    }

    return 0;
}


vector<pair<int, int>> solve(vector<pair<int, int>> & a) {
    sort(a.begin(), a.end(), [](pair<int, int> const & p1,
            pair<int, int> const & p2) {
        return p1.second > p2.second;
    });

    int n = a.size();
    for (int i = 0; i < n; ++i)
        a[i].second = i + 1;
    
    sort(a.begin(), a.end(), [](pair<int, int> const & p1,
            pair<int, int> const & p2) {
        return p1.first < p2.first;
    });

    return a;
}
