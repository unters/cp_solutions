#include <iostream>
#include <vector>
using namespace std;


int solve(int, int);


int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int answer = solve(n, k);
        cout << answer << "\n";
    }

    return 0;
}


int solve(int n, int k) {
    int answer = 0;
    for (int i = 0; i <= n; ++i) {
        bool seq_exists = true;

        int f_2 = n, f_1 = i;
        for (int j = 0; j < k - 2; ++j) {
            int f_0 = f_2 - f_1;
            if (f_0 > f_1) {
                seq_exists = false;
                break;
            }

            f_2 = f_1;
            f_1 = f_0;
        }

        if (seq_exists)
            ++answer;
    }

    return answer;
}
