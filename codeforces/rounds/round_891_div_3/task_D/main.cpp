#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


vector<int> solve(vector<int> &, vector<int> &);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];

        vector<int> b(n);
        for (int j = 0; j < n; ++j)
            cin >> b[j];

        auto strong_nodes = solve(a, b);
        cout << strong_nodes.size() << "\n";
        for (int node : strong_nodes)
            cout << node << " ";
        cout << "\n"; 
    }

    return 0;
}


vector<int> solve(vector<int> & a, vector<int> & b) {
    int n = a.size();
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        c[i] = a[i] - b[i];
    
    int max = *max_element(c.begin(), c.end());
    vector<int> strong_nodes;
    for (int i = 0; i < n; ++i)
        if (c[i] == max)
            strong_nodes.push_back(i + 1);

    return strong_nodes;
}
