#include <iostream>
#include <string>
using namespace std;


// 21:34
int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        
        if ((n % 2) == (m % 2))
            cout << "Tonya\n";

        else
            cout << "Burenka\n";
    }

    return 0;
}
