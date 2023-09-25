#include <iostream>
using namespace std;


int main(void) {
    int n;
    cin >> n;

    int cuts = 0; 
    long pieces = 1;
    while (pieces < n) {
        pieces *= 2;
        ++cuts;
    }

    cout << cuts << "\n";
    return 0;
}
