#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> z_function(std::string const &);


int main(void) {
    std::string t, p;
    std::getline(std::cin, t);
    std::getline(std::cin, p);

    int k;
    std::cin >> k;

    std::string s = p + "#" + t;
    auto z = z_function(s);

    std::string t_rev(t), p_rev(p);
    std::reverse(t_rev.begin(), t_rev.end());
    std::reverse(p_rev.begin(), p_rev.end());

    std::string s_rev = p_rev + "#" + t_rev;
    auto z_rev = z_function(s_rev);

    std::vector<int> indices;
    int n = s.size(), m = p.size();
    for (int i = p.size() + 1; i < s.size() - p.size() + 1; ++i) 
        if (z[i] + z_rev[m + 1 + (n - i - m)] + k >= m)
            indices.push_back(i - m);
    
    std::sort(indices.begin(), indices.end());
    std::cout << indices.size() << "\n";
    for (int index : indices)
        std::cout << index << " ";
    std::cout << "\n";

    return 0;
}


std::vector<int> z_function(std::string const & s) {
    std::vector<int> z(s.size(), 0);
    int l = 0, r = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];
    }

    return z;
}
