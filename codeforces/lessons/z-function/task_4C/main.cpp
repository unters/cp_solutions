#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> z_function(std::string const & s);


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    
    std::string s;
    s.reserve(1000001);
    std::getline(std::cin, s);
    for (int i = 0; i < q; ++i) {
        std::getline(std::cin, s);
        auto z = z_function(s);
        
        std::sort(z.begin(), z.end()); 
        for (int i = 1; i <= s.size(); ++i)
            std::cout << std::distance(std::lower_bound(
                z.begin(), z.end(), i), z.end()) + 1 << " ";
        std::cout << "\n";
    }

    return 0;
}


std::vector<int> z_function(std::string const & s) {
    std::vector<int> z(s.size(), 0);
    int l = 0, r = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];
    }

    /* Here RVO (copy-constructing) must take place.  */
    return z;
}
