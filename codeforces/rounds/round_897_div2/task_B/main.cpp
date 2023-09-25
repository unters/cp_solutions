#include <iostream>
#include <string>
using namespace std;


string solve(string &);


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string t = solve(s);
        cout << t << "\n";
    }

    return 0;
}


int count_mismatches(string const & s) {
    int n = s.size();

    int count = 0;
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i])
            ++count;
    return count;
}


string solve(string & s) {
    int n = s.size();
    string t(n + 1, '0');

    int c = count_mismatches(s);
    for (int i = 0; i < c; ++i)
        t[i] = '0';
    
    t[c] = '1';
    if (n % 2 == 0)
        for (int i = c + 1; i <= n - c; ++i)
            t[i] = t[i - 1] == '1' ? '0' : '1';

    else
        for (int i = c + 1; i <= n - c; ++i)
            t[i] = '1';

    // if (c == 0) {
    //     if (n % 2 == 0) {
    //         t[0] = '1';
    //         for (int i = 1; i <= n; ++i)
    //             t[i] = t[i - 1] == '1' ? '0' : '1';
    //     }

    //     else
    //         for (int i = 0; i <= n; ++i)
    //             t[i] = '1';
    // }

    // else {
    //     for (int i = 0; i < c; ++i)
    //         t[i] = '0';
    //     if (n % 2 == 0)
    //         for (int i = c; i <= n; ++i)
    //             t[i] = t[i - 1] == '1' ? '0' : '1';

    //     else
    //         for (int i = c; i <= n; ++i)
    //             t[i] = '1';
    // }

    return t;
}
