#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        /* Input.  */
        int n, k;
        cin >> n >> k;

        vector<long long> c(n);
        for (int i = 0; i < n; ++i)
            cin >> c[i];

        vector<int> p(k);
        for (int i = 0; i < k; ++i) {
            cin >> p[i];
            --p[i];
        }

        vector<vector<int>> recipes(n);
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;

            recipes[i] = m > 0 ? vector<int>(m) : vector<int>();
            for (int j = 0; j < m; ++j) {
                cin >> recipes[i][j];
                --recipes[i][j];
            }
        }

        /* Solution.  */
        for (int potion : p)
            c[potion] = 0;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == true)
                continue;

            stack<int> s;
            s.push(i);
            while(s.empty() == false) {
                int potion = s.top();

                if (recipes[potion].size() == 0) {
                    visited[potion] = true;
                    s.pop();
                    continue;
                }

                bool ready_to_brew = true;
                for (int recipe_potion : recipes[potion])
                    if (visited[recipe_potion] == false) {
                        ready_to_brew = false;
                        break;
                    }

                if (ready_to_brew == true) {
                    long long brew_cost = 0;
                    for (int recipe_potion : recipes[potion])
                        brew_cost += c[recipe_potion];
                    
                    c[potion] = min(c[potion], brew_cost);
                    visited[potion] = true;
                    s.pop();
                    continue;
                }

                for (int recipe_potion : recipes[potion])
                    if (visited[recipe_potion] == false)
                        s.push(recipe_potion);
            }
        }

        for (int i = 0; i < n; ++i)
            cout << c[i] << " ";
        cout << "\n";     
    }

    return 0;
}
