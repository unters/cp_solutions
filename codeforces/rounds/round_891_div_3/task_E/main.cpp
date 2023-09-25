#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;


vector<long long> solve(vector<int> &);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> x(n);
        for (int j = 0; j < n; ++j)
            cin >> x[j];

        auto answer = solve(x);
        for (long long value : answer)
            cout << value << " ";
        cout << "\n";
    }

    return 0;
}


vector<long long> solve(vector<int> & v) {
    int n = v.size();
    vector<pair<int, int>> x;
    for (int i = 0; i < n; ++i)
        x.push_back({ v[i], i });
    sort(x.begin(), x.end());

    vector<long long> prefix(n);
    prefix[0] = x[0].first;
    for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + x[i].first;

    vector<long long> suffix(n);
    suffix[n - 1] = x[n - 1].first;
    for (int i = n - 2; i >= 0; --i)
        suffix[i] = suffix[i + 1] + x[i].first;

    vector<long long> answer(n); 
    for (int i = 0; i < n; ++i) {
        long long s = x[i].first;
        long long ans = (long long)n + s * (2 * i - n) + suffix[i];
        if (i > 0)
            ans -= prefix[i - 1];
        answer[x[i].second] = ans;
    }

    return answer;
}
