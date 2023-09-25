#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solve(vector<int> const &);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        
        cout << solve(a) << "\n";
    }

    return 0;
}

int solve(vector<int> const & a) {
    int n = a.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            dp[i] = i == n - 1 ? 0 : dp[i + 1];
            continue;
        }

        dp[i] = i == n - 1 ? 1 : dp[i + 1] + 1;

        if (a[i] == a[i + 1]) 
            dp[i] = i + 2 < n ? min(dp[i], dp[i + 2] + 1) : 1;
        
        if (i + 2 < n && a[i] == a[i + 1] ^ a[i + 2]) 
            dp[i] = i + 3 < n ? min(dp[i], dp[i + 3] + 2) : min(dp[i], 2);
    }

    return dp[0];
}

