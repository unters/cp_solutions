#include <iostream>
#include <vector>
using namespace std;


vector<int> solve(vector<int> &);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        
        auto a = solve(b);

        cout << a.size() << "\n";
        for (int v : a)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}


vector<int> solve(vector<int> & b) {
    vector<int> a;
    a.push_back(b[0]);

    for (int i = 1; i < b.size(); ++i) {
        if (b[i] < b[i - 1])
            a.push_back(b[i]);
        a.push_back(b[i]);
    }

    return a;
}
