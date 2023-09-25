#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector<int> z_function(std::string const & s);


int main(void) {
    std::string s;
    std::getline(std::cin, s);

    /* "Mirroring" the given string.  */
    s += std::string(s.rbegin(), s.rend());    
    auto z = z_function(s);

    int n = s.size() / 2;
    for (int i = n; i < s.size(); ++i)
        if (z[i] == s.size() - i) {
            std::cout << z[i] << "\n";
            break;
        }

    return 0;
}


std::vector<int> z_function(std::string const & s) {
    int l = 0, r = 1;
    std::vector<int> z(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];
    }

    return z;
}
