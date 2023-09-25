#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;


long long solve(vector<int> &, int, int);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];        
        
        long long answer = solve(a, m, d);
        cout << answer << "\n";
    }

    return 0;
}


long long solve(vector<int> & a, int m, int d) {
    int n = a.size();
    
    multiset<int> ms;
    long long sum = 0;
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0)
            continue;

        sum += a[i];
        if (ms.size() == m) {
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }

        ms.insert(a[i]);
        max_sum = max(max_sum, sum - 1ll * d * (i + 1));
    }

    return max_sum;
}
