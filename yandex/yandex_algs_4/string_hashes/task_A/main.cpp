#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long const x = 257;
long long const mod = 1e9 + 7;

vector<long long> calculate_polynomial_hashcodes(string const & s);

int main(void) {
    string s;
    cin >> s;

    vector<long long> polynomial_hashcodes = calculate_polynomial_hashcodes(s);

    vector<long long> x_power(s.size() + 1);
    x_power[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
        x_power[i] = (x_power[i - 1] * x) % mod;
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int l, a, b;
        cin >> l >> a >> b;
        ++a, ++b;   // For convinience.

        long long hash_a = (polynomial_hashcodes[a + l - 1] + (polynomial_hashcodes[b - 1] * x_power[l]) % mod) % mod;
        long long hash_b = (polynomial_hashcodes[b + l - 1] + (polynomial_hashcodes[a - 1] * x_power[l]) % mod) % mod;
        cout << (hash_a == hash_b ? "yes" : "no") << "\n";
    }

    return 0;
}

vector<long long> calculate_polynomial_hashcodes(string const & s) {
    int n = s.size();
    vector<long long> polynomial_hashcodes(n + 1);
    polynomial_hashcodes[0] = 0;
    for (int i = 0; i < n; ++i) {
        polynomial_hashcodes[i + 1] = ((polynomial_hashcodes[i] * x) % mod + s[i]) % mod;
    }
    
    return polynomial_hashcodes;
}
