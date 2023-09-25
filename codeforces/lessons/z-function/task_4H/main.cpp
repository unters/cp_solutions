#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
 
std::vector<int> z_function(std::string const &);
 
 
int main(void) {
    std::string s;
    std::getline(std::cin, s);
 
    unsigned long long answer = 0;
    std::string t = "";
    for (int i = s.size() - 1; i >= 0; --i) {
        t = s[i] + t;
        auto z = z_function(t);
 
        auto it = std::max_element(z.begin(), z.end());
        int len = *it + 1;
        answer += (t.size() - len + 1) * (t.size() + len) / 2;
    }
 
    std::cout << answer << "\n";
 
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
 
    return z;
}