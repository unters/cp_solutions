#include <iostream>
#include <utility>
using namespace std;


int gcd(int, int);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        bool no_answer = false;
        pair<int, int> answer;
        if (l <= 2 && r <= 3)
            no_answer = true;

        else if (l == 2 && r >= 4)
            answer = { 2, 2 };

        else if (l % 2 == 0)
            answer = { l / 2, l / 2 };

        else if (r % 2 == 0)
            answer = { r / 2, r / 2 };
        
        else if (l == 1)
            answer = { 2, 2 };
        
        else if (l != r)
            answer = { (l + 1) / 2, (l + 1) / 2 };
        
        else {
            no_answer = true;
            for (int i = 3; 1ll * i * i <= 1ll * l; i += 2) {
                if (l % i == 0) {
                    no_answer = false;
                    answer = { i, l - i };
                    break;
                }
            }
        }

        if (no_answer == true)
            cout << "-1\n";
        else 
            cout << answer.first << " " << answer.second << "\n";
    }

    return 0;
}
