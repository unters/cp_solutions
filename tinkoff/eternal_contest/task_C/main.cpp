#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int> &, int, int);


int main(void) {
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int e;
    cin >> e;

    int answer = solve(v, t, e);
    cout << answer << "\n";
    return 0;
}


int solve(vector<int> & v, int t, int e) {
    int n = v.size();

    int t_left = 0;
    for (int i = e - 2; i >= 0; --i)
        t_left += v[i + 1] - v[i];

    int t_right = 0;
    for (int i = e; i < n; ++i)
        t_right += v[i] - v[i - 1];

    if (t_left <= t || t_right <= t)
        return t_left + t_right;
    
    else if (t_left < t_right)
        return 2 * t_left + t_right;
    
    else
        return t_left + 2 * t_right;
}
