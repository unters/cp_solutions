#include <iostream>
#include <string>
using namespace std;


void solve(string &);


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        solve(s); 
        cout << s << "\n";
    }   

    return 0;
}


void solve(string & s) {
    int n = s.size();

    int last_k = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i + 1] < '5') 
            continue;
        
        if (s[i] == '9') {
            int j = i - 1;
            while(i >= 0 && s[i] == '9')
                --i;

            if (i < 0) {
                s = "1";
                s.append(n, '0');
                return;
            }

            s[i] = s[i] + 1;
            for (int j = i + 1; j <= last_k; ++j)
                s[j] = '0';
            last_k = i;
        }

        else {
            s[i] = s[i] + 1;
            for (int j = i + 1; j <= last_k; ++j)
                s[j] = '0';
            last_k = i;
        }
    }

    if (s[0] >= '5') {
        s = "1";
        s.append(n, '0');
        return;
    }
}
