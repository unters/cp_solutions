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

        int index_1 = 0;
        int index_3 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                index_1 = i;
            else if (s[i] == '3')
                index_3 = i;
        }

        int answer = index_1 < index_3 ? 13 : 31;
        cout << answer << "\n";
    }

    return 0;
}
