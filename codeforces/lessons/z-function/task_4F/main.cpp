#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::string solve(std::string const &, std::string const &);

std::vector<int> z_function(std::string const &);


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    
    std::string s, t;
    std::getline(std::cin, s);
    for (int i = 0; i < q; ++i) {
        std::getline(std::cin, s);
        std::getline(std::cin, t);
        std::cout << solve(s, t) << "\n"; 
    }

    return 0;
}


std::string solve(std::string const & s, std::string const & t) {
    std::string st = s + "#" + t;
    auto z_st = z_function(st);
    
    int max_st = 0;
    for (int i = s.size() + 1; i < z_st.size(); ++i)
        // s is a substring of t.
        if (z_st[i] == s.size())
            return t;

        // prefix of s is a suffix of t.
        else if (i + z_st[i] == z_st.size()) {
            max_st = z_st[i];
            break;
        }

    std::string ts = t + "#" + s;
    auto z_ts = z_function(ts);
    
    int max_ts = 0;
    for (int i = t.size() + 1; i < z_ts.size(); ++i)
        // t is a substring of s.
        if (z_ts[i] == t.size())
            return s;

        // prefix of t is a suffix of s.
        else if (i + z_ts[i] == z_ts.size()) {
            max_ts = z_ts[i];
            break;
        } 

    // Trying to increase chances for NRVO.
    std::string answer;
    if (max_st > max_ts)
        answer =  t.substr(0, t.size() - max_st) + s;
    else
        answer =  s.substr(0, s.size() - max_ts) + t;
    return answer;
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
