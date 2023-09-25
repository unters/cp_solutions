#include <iostream>
#include <vector>
#include <algorithm>


struct compare {
    bool operator() (std::pair<int, long long> p1, std::pair<int, long long> p2) {
        if (p1.first > p2.first)
            return true;
        if ((p1.first == p2.first) && (p1.second < p2.second))
            return true;
        return false;
    }
};


std::pair<int, long long> get_result(std::vector<int> &, int);


int main(void) {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n, m, h;
        std::cin >> n >> m >> h;

        std::vector<int> v(m);
        /* Rudolph.  */
        for (int k = 0; k < m; ++k)
            std::cin >> v[k];
        auto rudolph_res = get_result(v, h);

        std::vector<std::pair<int, long long>> rating;
        /* Other participants.  */
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < m; ++k)
                std::cin >> v[k];
            rating.push_back(get_result(v, h));
        }

        std::sort(rating.begin(), rating.end(), compare());
        auto it = std::lower_bound(rating.begin(), rating.end(),
            rudolph_res, compare());
        std::cout << std::distance(rating.begin(), it) + 1 << "\n";
    }

    return 0;
}


std::pair<int, long long> get_result(std::vector<int> & v, int h) {
    std::sort(v.begin(), v.end());
    std::pair<int, long long> p({ 0, 0 });

    int time_passed = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (time_passed + v[i] > h)
            break;
        
        ++p.first;
        p.second += time_passed + v[i];
        time_passed += v[i];
    }
    
    // std::cout << "DEBUG: " << p.first << " " << p.second << "\n";

    return p;
}