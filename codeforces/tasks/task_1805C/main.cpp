#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
    int t;
    std::cin >> t;

    long n, m; 
    for (long i = 0; i < t; ++i) {
        std::cin >> n >> m;

        std::vector<long long> lines(n);
        for (long j = 0; j < n; ++j) 
            std::cin >> lines[j];
    
        std::sort(lines.begin(), lines.end()); 
    
        long long a, b, c;
        for (long j = 0; j < m; ++j) {
            std::cin >> a >> b >> c;
            long index = std::lower_bound(lines.begin(), lines.end(), b) - \
                lines.begin();

            /* Can't use std::pow because it returns value of a
             * floating-point type.  */
            if (index < n && (b - lines[index]) * (b - lines[index]) 
                    < 4 * a * c) {
                std::cout << "YES\n" << lines[index] << std::endl;
                continue;
            }            

            if (index > 0 && (lines[index - 1] - b) * (lines[index - 1] - b)
                    < 4 * a * c) {
                std::cout << "YES\n" << lines[index - 1] << std::endl;
                continue;
            }

            std::cout << "NO\n";
        }
    }

    return 0;
}