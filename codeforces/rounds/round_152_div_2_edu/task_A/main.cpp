#include <iostream>
#include <string>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int b, c, h;
        cin >> b >> c >> h;

        int bread = b - 1;
        int contents = c + h;

        if (bread <= contents)
            cout << bread * 2 + 1 << "\n";
        else
            cout << contents * 2 + 1 << "\n";
    }

    return 0;
}
