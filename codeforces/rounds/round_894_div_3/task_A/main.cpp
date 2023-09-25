#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;
    
    array<char, 4> const letters = {
        { 'v', 'i', 'k', 'a' }
    };

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<string> carpet(n);
        getline(cin, carpet[0]);
        for (int i = 0; i < n; ++i)
            getline(cin, carpet[i]);

        int next_letter = 0;
        for (int x = 0; x < m; ++x) {
            if (next_letter == 4)
                break;

            for (int y = 0; y < n; ++y) 
                if (carpet[y][x] == letters[next_letter]) {
                    ++next_letter;
                    break;
                }
        }

        string answer = next_letter == 4 ? "YES" : "NO";
        cout << answer << "\n";
    }

    return 0;
}
