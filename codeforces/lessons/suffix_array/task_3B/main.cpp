#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


vector<int> count_sort(vector<int> &, vector<int> &);


int main(void) {
    string s;
    getline(cin, s);
    s.append(1, '$');
    int n = s.size();

    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = { s[i], i };

        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) 
            p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            c[p[i]] = c[p[i - 1]];
            if (a[i].first != a[i - 1].first)
                ++c[p[i]];
        }
    }

    int k = 0;
    while((1 << k) < n) {
        for (int i = 0; i < n; ++i)
            p[i] = (p[i] - (1 << k) + n) % n;
        
        auto p_new = count_sort(p, c);
        p = p_new;

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            c_new[p[i]] = c_new[p[i - 1]];
            pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
            pair<int, int> curr = { c[p[i]], c[(p[i] + (1 << k)) % n] };
            if (prev != curr)
                ++c_new[p[i]];
        }

        c = c_new;
        ++k;
    }

    // /* Debug.  */
    // for (int x : p)
    //     cout << x << " ";
    // cout << "\n\n";

    int m;
    cin >> m;

    string t;
    getline(cin, t);
    while(m--) {
        getline(cin, t);
        
        int count = n - 1;
        int l = 0;
        while(count > 0) {
            int step = count / 2;
            int m = l + step;
            if (s.substr(p[m], min(s.size() - p[m], t.size())) < t) {
                l = m + 1;
                count -= step + 1;
            }

            else
                count = step;
        }

        int min_index = l;

        count = n - 1;
        l = 0;
        while(count > 0) {
            int step = count / 2;
            int m = l + step;
            if (!(s.substr(p[m], min(s.size() - p[m], t.size())) > t)) {
                l = m + 1;
                count -= step + 1;
            }

            else
                count = step;
        }

        int max_index = l;
        
        int answer = 0;
        if (s.substr(p[min_index], min(n - p[min_index], (int)t.size())) == t)
            answer = max_index - min_index;
        if (s.substr(p[max_index], min(n - p[max_index], (int)t.size())) == t)
            answer += 1;
        cout << answer << "\n";
    }

    return 0;
}


vector<int> count_sort(vector<int> & p, vector<int> & c) {
    int n = p.size();
    
    vector<int> cnt(n, 0);
    for (int x : c)
        ++cnt[x];

    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i)
        pos[i] = pos[i - 1] + cnt[i - 1];
    
    vector<int> p_new(n);
    for (int x : p)
        p_new[pos[c[x]]++] = x;
    
    return p_new;
}
