#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


int main(void) {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        
        std::vector<int> heights(n, 0);
        for (int j = 0; j < n; ++j) {
            int a, b;
            std::cin >> a >> b;
            heights[j] = a - b;
        }

        std::sort(heights.begin(), heights.end(), std::greater<int>());
        auto it = std::lower_bound(heights.begin(), heights.end(), 0, 
            std::greater<int>());
        std::cout << std::distance(heights.begin(), it) << "\n";
    }

    return 0;
}
