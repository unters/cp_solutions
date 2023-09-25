#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;


int main(void) {
    int n, c, d;
    cin >> n >> c >> d;

    int neg_count = 0;
    int zero_count = 0;
    pair<long, int> min_nonnegative = { INT64_MAX, -1 };
    vector<long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0)
            ++zero_count;
        else if (a[i] >= 0)
            if (a[i] < min_nonnegative.first)
                min_nonnegative = { a[i], i };
        else if (a[i] < 0)
            ++neg_count;
    }

    if (neg_count % 2 == 0 && min_nonnegative.second != -1) {
        if (min_nonnegative.first - c * d < 0) {
            int substractions = min_nonnegative.first / d + 1;
            a[min_nonnegative.second] -= substractions * d;
            c -= substractions;
        }
    }
    
    if (zero_count > c) {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "\n";
        return 0;
    }
    
    c -= zero_count;
    neg_count += zero_count;
    for (int i = 0; i < n; ++i)
        if (a[i] == 0)
            a[i] += d;

    typedef pair<long, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> pos, neg;
    for (int i = 0; i < n; ++i)
        if (a[i] > 0)
            pos.push({ a[i], i });
        else
            neg.push({ a[i], i });

    while(c--) {
        if (pos.empty() == false && neg.empty() == false) {
            auto min_pos = pos.top();
            auto min_neg = neg.top();

            if (min_pos.first < -1ll * min_neg.first) {
                pos.pop();
                min_pos.first += d;
                a[min_pos.second] += d;
                pos.push(min_pos);
            }

            else {
                neg.pop();
                min_neg.first -= d;
                a[min_neg.second] -= d;
                neg.push(min_neg);
            }
        }

        else if (pos.empty() == false) {
            auto min_pos = pos.top();
            pos.pop();

            min_pos.first -= d;
            a[min_pos.second] -= d;
            pos.push(min_pos);
        }

        else {
            auto min_neg = neg.top();
            neg.pop();

            min_neg.first -= d;
            a[min_neg.second] -= d;
            neg.push(min_neg);
        }
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}
