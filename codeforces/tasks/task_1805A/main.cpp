#include <iostream>


int main(void) {
    int t;
    std::cin >> t;

    int n, a;
    for (int i = 0; i < t; ++i) {     
        std::cin >> n;

        int result = 0;
        for (int j = 0; j < n; ++j) {
            std::cin >> a;
            result ^= a; 
        }

        if (n % 2 == 0 && result != 0)
            std::cout << "-1\n";

        else if (n % 2 == 0 && result == 0)
            std::cout << "0\n";
        
        else
            std::cout << result << std::endl;
    }

    return 0;
}