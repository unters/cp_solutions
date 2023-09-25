#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main(void) {
    int n, k;
    cin >> n >> k;

    string p;
    getline(cin, p);
    getline(cin, p);

    vector<int> counter(26, 0);
    for (char c : p)
        ++counter[c - 'a'];
    
    int different_symbols_count = 0;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (int i : counter)
        if (i != 0) {
            pq.push(i);
            ++different_symbols_count;
        }
    
    int deleted_symbols_count = 0;
    while(k > 0 && pq.empty() == false) {
        int count = pq.top();
        if (k < count)
            break;

        k -= count;
        pq.pop();
        ++deleted_symbols_count;
    }

    cout << different_symbols_count - deleted_symbols_count << "\n";

    return 0;
}
