#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        std::vector<int> odd, even;
        std::vector<bool> isEven(n, false);
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            if (val % 2 == 0) {
                even.push_back(val);
                isEven[j] = true;
            }

            else
                odd.push_back(val);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        bool is_sortable = true;
        int even_id = 0, odd_id = 0;
        for(int j = 0; j < n; ++j) {
            if (even_id >= even.size() || odd_id >= odd.size())
                break;

            int even_min = even[even_id];
            int odd_min = odd[odd_id];

            if (even_min < odd_min) {
                if (isEven[j] == true)
                    ++even_id;
                else {
                    is_sortable = false;
                    break;
                }
            }

            else {
                if (isEven[j] == false)
                    ++odd_id;
                else {
                    is_sortable = false;
                    break;
                }
            }
        }

        if (is_sortable)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
