#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.size();
        int count = 0;
        if (s[0] == 'B' || s[n - 1] == 'B') {
            for (int i = 0; i < n; ++i)
                if (s[i] == 'A')
                    ++count;
        }

        else {
            int min_seq = INT32_MAX;
            int cur_seq = 0;
            bool there_is_double_b = false;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'B' && (i + 1 < n && s[i + 1] == 'B'))
                    there_is_double_b = true;
                
                else if (s[i] == 'A') {
                    ++count;
                    ++cur_seq;
                }

                else if(s[i] == 'B' && cur_seq != 0) {
                    min_seq = min(min_seq, cur_seq);
                    cur_seq = 0;
                }
            }

            min_seq = min(min_seq, cur_seq);
            if (there_is_double_b == false) 
                count -= min_seq;
        }

        cout << count << "\n";
    }

    return 0;
}

