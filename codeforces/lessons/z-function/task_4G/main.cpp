#include <iostream>
#include <vector>


std::vector<int> manaker_odd(std::vector<int> const &);


int main(void) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(2 * n + 1, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> v[2 * i + 1];

    auto rad = manaker_odd(v);
    for (int i = 2; i < v.size() / 2 + 1; i += 2)
        if (i == rad[i])        
            std::cout << n - (rad[i] / 2) << " ";

    std::cout << n << "\n";
    return 0;
}


std::vector<int> manaker_odd(std::vector<int> const & v) {
    std::vector<int> d(v.size(), 0);
    int l = 0, r = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i < r)
            d[i] = std::min(d[l + r - i], r - i); 
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < v.size()
            && v[i - d[i] - 1] == v[i + d[i] + 1]) ++d[i];
        if (i + d[i] > r)
            l = i - d[i], r = i + d[i];
    }

    return d;
}
