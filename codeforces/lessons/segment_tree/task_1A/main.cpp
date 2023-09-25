#include <iostream>
#include <vector>
using namespace std;


class segtree {
public:
    segtree(vector<int> & a) {
        size = 1;
        while (size < a.size())
            size *= 2;
        tree.assign(2 * size - 1, 0);

        build(a, 0, 0, size);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

private:
    int size;
    vector<long long> tree;
    
    void build(vector<int> & a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = a[lx];
        }
        
        else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1)
            tree[x] = v;
        
        else {
            int m = (lx + rx) / 2;
            if (i < m)
                set(i, v, 2 * x + 1, lx, m);
            else
                set(i, v, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l)
            return 0;
        
        if (lx >= l && rx <= r)
            return tree[x];
        
        int m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
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
                cout << st.sum(l, r) << "\n";
                break;
        }
    }

    return 0;
}
