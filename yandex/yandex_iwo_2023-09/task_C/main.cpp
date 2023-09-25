#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> nodes(n + 1, vector<int>()); 
    for (int i = 1; i <= n; ++i) {
        int r;
        cin >> r;
        nodes[r].push_back(i);
    }

    
    int height = 0;
    int heighest_node = 0;
    
    queue<int> q;
    q.push(0);

    while(q.empty() == false) {
        heighest_node = q.front();
        ++height;

        int size = q.size();
        for (int i = 0; i < size; ++i) {
            for (int node : nodes[q.front()])
                q.push(node);
            q.pop();
        }
    }

    cout << heighest_node << "\n";
    return 0;
}
