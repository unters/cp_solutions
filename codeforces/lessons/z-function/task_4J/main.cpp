#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> z_function(std::string const &);


int main(void) {
    std::string s;
    std::getline(std::cin, s);

    s += s;
    auto z = z_function(s);
    int count = 1;
    for (int i = 1; i < s.size() / 2; ++i)
        if (z[i] == s.size() - i)
            continue;

        else if (s[i + z[i]] < s[z[i]])
            ++count;

    std::cout << count << "\n";       
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
