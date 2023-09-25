#include <iostream>
using namespace std;


int main(void) {
    long long n, m, c2, c5;
    cin >> n >> m >> c2 >> c5;

    if (m <= n) {
        cout << "0\n";
        return 0;
    }

    if (4ll * c2 < c5)
        c5 = 4ll * c2;

    long long price = ((m - n) / 4) * c5;
    if (((m - n) % 4) * c2 < c5)
        price += ((m - n) % 4) * c2;
    else
        price += c5;

    cout << price << "\n";
    return 0;
}
