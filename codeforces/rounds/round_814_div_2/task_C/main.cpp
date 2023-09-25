#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, q;
        cin >> n >> q;

        /* (power, index).  */
        vector<int> power(n);
        deque<int> dq;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;

            power[j] = a;
            dq.push_back(j);
        }

        vector<vector<int>> wins(n, vector<int>());
        for (int round = 1; round <= n; ++round) {
            int fighter_1 = dq[0];
            int fighter_2 = dq[1];

            if (power[fighter_1] > power[fighter_2]) {
                dq.pop_front();
                dq[0] = fighter_1;
                dq.push_back(fighter_2);
                wins[fighter_1].push_back(round); 
            }

            else {
                dq.pop_front();
                dq.push_back(fighter_1);
                wins[fighter_2].push_back(round);
            }
        }

        for (int j = 0; j < q; ++j) {
            int id, k;
            cin >> id >> k;

            if (power[id - 1] == n) {
                if (wins[id - 1][0] > k)
                    cout << "0\n";
                else
                    cout << k - wins[id - 1][0] + 1 << "\n";
                continue;
            }

            else if (wins[id - 1].empty() == true)
                cout << "0\n";

            else {
                auto it = lower_bound(wins[id - 1].rbegin(),
                    wins[id - 1].rend(), k, greater<int>());
                cout << distance(it, wins[id - 1].rend()) << "\n";
            }
        }
    }

    return 0;
}
