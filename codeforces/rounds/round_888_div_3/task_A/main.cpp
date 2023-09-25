#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m, k, h;
        std::cin >> n >> m >> k >> h;

        std::vector<int> v(n);
        for (int j = 0; j < n; ++j)
            std::cin >> v[j];

        int count = 0;
        for (int j = 0; j < n; ++j) {
            int d = v[j] > h ? v[j] - h : h - v[j];
            if (d == 0)
                continue;
            if (d % k == 0 && d / k < m)
                ++count;
        }

        std::cout << count << "\n";
    }
}
