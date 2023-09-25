#include <iostream>
#include <string>
#include <algorithm>


std::string period(std::string & s) {
    int n = s.size();
    int * z = new int[n];
    for (int i = 0; i < n; ++i)
        z[i] = 0;
    
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r)
            z[i] = std::min(z[i - l], r - i);
        while(i + z[i] < n && s[z[i]] == s[z[i] + i])
            ++z[i];
        if (i + z[i] >= r)
            l = i, r = i + z[i];
    }

    for (int i = 0; i < n; ++i)
        if (i + z[i] == n)
            return s.substr(0, i);

    return s;
}


int main(void) {
    int t;
    std::cin >> t;

    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < t; ++i) {
        std::getline(std::cin, s);
        std::cout << period(s) << std::endl;
    }
    return 0;
}