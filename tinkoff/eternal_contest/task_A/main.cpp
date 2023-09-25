#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int answer = a + (d > b ? d - b : 0) * c;
    cout << answer << "\n";
    
    return 0;
}