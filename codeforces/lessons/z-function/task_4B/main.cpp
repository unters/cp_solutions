#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int calculate_cyclic_shift(std::string & s, std::string & t);


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    std::string s, t;
    std::getline(std::cin, s);
    s.reserve(1000001);
    t.reserve(3000002);

    for (int i = 0; i < q; ++i) {
        std::getline(std::cin, s);
        std::getline(std::cin, t);
        std::cout << calculate_cyclic_shift(s, t) << "\n";    
    }

    return 0;
}


int calculate_cyclic_shift(std::string & s, std::string & t) {
    t += "#" + s + s;    
    std::vector<int> z(t.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < t.size() - s.size(); ++i) { 
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while(i + z[i] < t.size() && t[i + z[i]] == t[z[i]])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];

        if (z[i] == s.size())
            return i - z[i] - 1;    
    }

    return -1;
}