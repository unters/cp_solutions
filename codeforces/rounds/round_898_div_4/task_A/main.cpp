#include <iostream>
#include <string>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        char a, b, c;
        cin >> a >> b >> c;

        string answer = (a == 'a' || b == 'b' || c == 'c') ? "YES" : "NO";
        cout << answer << "\n";
    }

    return 0;
}

