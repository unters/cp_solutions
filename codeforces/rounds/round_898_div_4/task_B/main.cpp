#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int zero_count = 0;
        int min_value = 10;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0)
                ++zero_count;
            min_value = min(min_value, a[i]);
        }
            
        if (zero_count > 1) {
            cout << "0\n";
            continue;
        }

        int answer = 1;
        for (int i = 0; i < n; ++i)
            answer = a[i] == 0 ? answer : answer * a[i];

        if(min_value != 0)
            answer = answer / min_value * (min_value + 1);

        cout << answer << "\n";     
    }

    return 0;
}

