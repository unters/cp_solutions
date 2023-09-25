#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> z_function(std::string s);


int main(void) {
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);

    auto z_1 = z_function(t + '#' + s); 
    std::reverse(t.begin(), t.end());
    auto z_2 = z_function(s + '#' + t);

    for (int i = 0; i <= z_2[s.size() + 1]; ++i)
        if (z_1[s.size() + 1 + i] + i == s.size()) {
            std::cout << "Yes\n" << i << "\n";
            return 0;
        } 

    std::cout << "No\n";
    return 0;
}


std::vector<int> z_function(std::string s) {
    std::vector<int> z(s.size(), 0);
    int l = 0, r = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i]; 
    }

    return z;
}