#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class segtree {
public:
    segtree(vector<int> & a) {
        size = 1;
        while (size < a.size())
            size *= 2;
        tree.assign(2 * size - 1, { INT32_MAX, 0 });

        stack<pair<int, pair<int, int>>> s;
        vector<bool> processed(2 * size - 1, false);

        s.push({ 0, { 0, size } });
        while(s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            if (rx - lx == 1) {
                if (lx < a.size())
                    tree[x] = { a[lx], 1 };
                s.pop();
            }

            else if (processed[x] == true) {
                if (tree[2 * x + 1].first == tree[2 * x + 2].first)
                    tree[x] = { tree[2 * x + 1].first,
                        tree[2 * x + 1].second + tree[2 * x + 2].second };
                
                else if (tree[2 * x + 1].first < tree[2 * x + 2].first)
                    tree[x] = tree[2 * x + 1];

                else
                    tree[x] = tree[2 * x + 2];
                s.pop();
            }

            else {
                processed[x] = true;
                int m = (lx + rx) / 2;
                s.push({ 2 * x + 1, { lx, m } });
                s.push({ 2 * x + 2, { m, rx } });
            }
        }
    }

    void set(int i, int v) {
        stack<pair<int, pair<int, int>>> s;
        vector<bool> processed(2 * size - 1, false);

        s.push({ 0, { 0, size }});
        while(s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            if (rx - lx == 1) {
                tree[x] = { v, 1 };
                s.pop();
            }

            else if (processed[x] == true) {
                if (tree[2 * x + 1].first == tree[2 * x + 2].first)
                    tree[x] = { tree[2 * x + 1].first,
                        tree[2 * x + 1].second + tree[2 * x + 2].second };
                
                else if (tree[2 * x + 1].first < tree[2 * x + 2].first)
                    tree[x] = tree[2 * x + 1];

                else
                    tree[x] = tree[2 * x + 2];
                s.pop();
            }

            else {
                processed[x] = true;
                int m = (lx + rx) / 2;
                if (i < m) 
                    s.push({ 2 * x + 1, { lx, m }});
                else
                    s.push({ 2 * x + 2, { m, rx }});
            }
        }
    }

    pair<int, int> min_count(int l, int r) {
        stack<pair<int, pair<int, int>>> s;
        pair<int, int> answer = { INT32_MAX, 0 };

        s.push({ 0, { 0, size } });
        while (s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            s.pop();
            if (rx <= l || lx >= r) 
                continue;

            if (lx >= l && rx <= r) {
                if (tree[x].first < answer.first)
                    answer = tree[x];
                else if (answer.first == tree[x].first)
                    answer = { answer.first, answer.second + tree[x].second };
            }

            else {
                int m = (lx + rx) / 2;
                s.push({ 2 * x + 1, { lx, m } });
                s.push({ 2 * x + 2, { m, rx } });
            }
        }

        return answer;
    }

private:
    int size;
    vector<pair<int, int>> tree;
};


int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    segtree st(a);
    while (m--) {
        int c;
        cin >> c;
        
        switch (c) {
            case 1:
                int i, v;
                cin >> i >> v;
                st.set(i, v);
                break;
            case 2:
                int l, r;
                cin >> l >> r;
                auto p = st.min_count(l, r);
                cout << p.first << " " << p.second << "\n";
                break;
        }
    }

    return 0;
}
