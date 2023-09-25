#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>   // for memset


int main(void) {
    std::string s;
    std::getline(std::cin, s);

    int n = s.size();
    int * z = new int[n];
    memset(z, 0, sizeof(int) * n);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = 0; i < n; ++i)
        std::cout << z[i] << " ";
    std::cout << std::endl;

    delete [] z;
    return 0;
}