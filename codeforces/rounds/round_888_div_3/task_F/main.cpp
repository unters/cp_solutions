#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


tuple<int, int, int> solve(vector<pair<int, int>> &, int);


int main(void){
    int t;
    cin >> t;

    while(t--){ 
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            int value;
            cin >> value;

            a[i] = { value, i + 1 };
        }

        auto answer = solve(a, k);
        cout << get<0>(answer) << " " << get<1>(answer)
            << " " << get<2>(answer) << "\n";
    }

    return 0;
}


tuple<int, int, int> solve(vector<pair<int, int>> & a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());    
    int limit = (1 << k) - 1;

    auto a_i = a[0], a_j = a[1];
    int x = a_i.first ^ limit;
    int max_result = (a_i.first ^ x) & (a_j.first ^ x);
    for (int i = 2; i < n; ++i) {
        int cur_x = a[i].first ^ limit;
        int cur_result = (a[i].first ^ cur_x) & (a[i - 1].first ^ cur_x);
        if (cur_result > max_result) {
            a_i = a[i];
            a_j = a[i - 1];
            x = cur_x;
            max_result = cur_result;
        }
    }

    return { a_i.second, a_j.second, x };
}
