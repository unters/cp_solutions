#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long sum = 0;
        int min_first = INT32_MAX;
        int min_second = INT32_MAX;
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;

            pair<int, int> curr_min = { INT32_MAX, INT32_MAX };
            for (int j = 0; j < m; ++j) {
                int a;
                cin >> a;

                if (a < curr_min.first)
                    curr_min = { a, curr_min.first };
                else if (a < curr_min.second)
                    curr_min = { curr_min.first, a };
            }

            min_first = min(min_first, curr_min.first);
            min_second = min(min_second, curr_min.second);
            sum += curr_min.second;
        }

        sum += min_first - min_second;
        cout << sum << "\n";
    }

    return 0;
}
