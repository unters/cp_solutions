#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    string s;
    getline(cin, s);
    while(t--) {
        getline(cin, s);
        int n = s.size();

        bool valid = true;
        stack<pair<int, bool>> sp;

        int cur_size = 0;
        for (char c : s) {
            if (c == '+') {
                ++cur_size;
            }
            
            else if (c == '-') {
                /* According to problem statement Monocarp did not perform
                 * substractions on an empty array. But what if he did?  */
                if (cur_size == 0) {
                    valid = false;
                    break;
                }

                --cur_size;
                if (sp.empty() == false && cur_size < sp.top().first) {
                    if (sp.top().second == true) {
                        sp.pop();
                        sp.push({ cur_size, true });
                    }
                    
                    else
                        sp.pop();
                }
            }
            
            else {
                if (cur_size < 2 && c == '0') {
                    valid = false;
                    break;
                }

                if (sp.empty() == false && sp.top().second == false
                        && c == '1') {
                    valid = false;
                    break;
                }

                if (sp.empty() == false && sp.top().first == cur_size
                        && ((c == '1') != sp.top().second)) {
                    valid = false;
                    break;
                }

                if (!(sp.empty() == false && sp.top().first == cur_size)
                        && cur_size > 1)
                    sp.push({ cur_size, (c == '1') });
            }
        }

        string answer = valid ? "YES" : "NO";
        cout << answer << "\n";     
    }

    return 0;
}
