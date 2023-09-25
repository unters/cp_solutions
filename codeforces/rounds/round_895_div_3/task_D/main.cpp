#include <iostream>
using namespace std;


long long gcd(long long, long long);

long long lcm(long long, long long);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        long long both_count = n / lcm(x, y);
        long long incr_count = n / x - both_count;
        long long decr_count = n / y - both_count;

        long long sum = 0;
        sum += (n - incr_count + 1 + n) * incr_count / 2;
        sum -= (1 + decr_count) * decr_count / 2;

        cout << sum << "\n";
    }

    return 0;
}


long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);

    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }

    return b;
}


long long lcm(long long a, long long b){
    return abs(a * b) / gcd(a, b);
}