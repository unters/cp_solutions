#include <iostream>
#include <string>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    string s;
    getline(cin, s);
    while(t--) {
        getline(cin, s);

        if (s == "()") {
            cout << "NO\n";
            continue;
        }

        int n = s.size();
        string answer = "";
        if (s.find(")(") != string::npos) {
            answer.append(n, '(');
            answer.append(n, ')');
        }

        else {
            answer = string(2 * n, ' ');
            for (int i = 0; i < 2 * n; i += 2) {
                answer[i] = '(';
                answer[i + 1] = ')';       
            }
        }

        cout << "YES\n" << answer << "\n";
    }

    return 0;
}
