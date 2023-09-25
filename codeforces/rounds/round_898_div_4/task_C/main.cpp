#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        string s;
        int score = 0;
        for (int y = 0; y < 10; ++y) {
            cin >> s;
            for (int x = 0; x < 10; ++x)
                if (s[x] == 'X')
                    score += min(min(x + 1, 10 - x), min(y + 1, 10 - y));
        }

        cout << score << "\n";
    }

    return 0;
}

