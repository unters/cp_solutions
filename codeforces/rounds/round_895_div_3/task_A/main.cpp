#include <iostream>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int d = a > b ? a - b : b - a;
        d = d / 2 + (d % 2 == 0 ? 0 : 1);

        int answer = d / c + (d % c == 0 ? 0 : 1);
        cout << answer << "\n";
    }

    return 0;
}
