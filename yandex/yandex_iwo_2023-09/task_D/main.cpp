#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


int main(void) {
    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<int>> sidewalks(k, vector<int>());
    for (int i = 0; i < n; ++i) {
        int d, w;
        cin >> d >> w;
        if (sidewalks[w - 1].empty() == true || sidewalks[w - 1].back() != d)
            sidewalks[w - 1].push_back(d);
    }
    
    int mine_sites_count = 0;
    for (auto s : sidewalks)
        if (s.empty() == false)
            ++mine_sites_count;

    if (mine_sites_count > m) {
        cout << "-1\n";
        return 0;
    }

    long long total_sadness = 0;
    for (auto s : sidewalks)
        if (s.empty() == false)
            total_sadness += 1ll * s.back() - 1ll * s.front();

    priority_queue<int, vector<int>, greater<int>> pq;
    int e = m - mine_sites_count;
    for (auto s : sidewalks)
        if (s.empty() == false && s.size() > 1)
            for (int i = 1; i < s.size(); ++i) {
                pq.push(s[i] - s[i - 1]);
                if (pq.size() > e)
                    pq.pop();
            }
    
    while(pq.empty() == false) {
        total_sadness -= 1ll * pq.top();
        pq.pop();
    }

    cout << total_sadness << "\n";
    return 0;
}
