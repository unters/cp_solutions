#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cmath>
using namespace std;


class segtree {
public:
    void print() {
        cout << "Debug: ";
        for (int i = 0; i < size; ++i)
            cout << tree[i] << " ";
        cout << "\n";
    }

    segtree(vector<int> & a) {
        size = 1;
        while(size < a.size())
            size *= 2;
        tree.assign(2 * size + 1, 0);
        
        stack<pair<int, pair<int, int>>> s;
        vector<bool> processed(size, false);

        s.push({ 0, { 0, size } });
        while(s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            if (rx - lx == 1) {
                if (lx < a.size())
                    tree[x] =  a[lx];
                s.pop();
            }

            else if (processed[x]) {
                tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
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
        vector<bool> processed(size, false);

        s.push({ 0, { 0, size } });
        while (s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            if (rx - lx == 1) {
                tree[x] = v;
                s.pop();
            }

            else if (processed[x]) {
                tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
                s.pop();
            }

            else {
                processed[x] = true;
                int m = (lx + rx) / 2;
                if (i < m)
                    s.push({ 2 * x + 1, { lx, m } });
                else
                    s.push({ 2 * x + 2, { m, rx } });
            }
        }
    }

    int segmin(int l, int r) {
        stack<pair<int, pair<int, int>>> s;

        int min_ans = INT32_MAX;
        s.push({ 0, { 0, size }});
        while (s.empty() == false) {
            auto p = s.top();
            int x = p.first;
            int lx = p.second.first;
            int rx = p.second.second;

            s.pop();
            if (rx <= l || lx >= r)
                continue;
            
            else if (lx >= l && rx <= r)
                min_ans = min(min_ans, tree[x]);

            else {
                int m = (lx + rx) / 2;
                s.push({ 2 * x + 1, { lx, m } });
                s.push({ 2 * x + 2, { m, rx } });
            }
        }

        return min_ans;
    }

private:
    int size;
    vector<int> tree;
};


int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    segtree st(a);
    while(m--) {
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
                cout << st.segmin(l, r) << "\n";
                break;
        }
    }

    return 0;
}
