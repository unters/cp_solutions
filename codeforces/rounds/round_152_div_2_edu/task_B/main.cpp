#include <iostream>
#include <queue>
#include <utility>
using namespace std;


struct comparator {
    bool operator() (pair<int, int> p_1, pair<int, int> p_2) {
        if (p_1.first < p_2.first)
            return true;
        
        if (p_1.first == p_2.first && p_1.second > p_2.second)
            return true;
        
        return false;
    }
};


int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (int i = 0; i < n; ++i) {
            int hp;
            cin >> hp;

            pq.push({ hp % k == 0 ? k : hp % k, i + 1 });
        }
        
        while(pq.empty() == false) {
            auto monster = pq.top();
            // cout << "Fight begins\t" << monster.first << " " << monster.second << "\n";
            pq.pop();

            if (pq.empty() == false) {
                auto next_monster = pq.top();
                int hp_difference = monster.first - next_monster.first;

                int hits = hp_difference / k;
                if (hits == 0)
                    ++hits;

                else if (hp_difference % k != 0)
                    ++hits;
                
                monster.first -= hits * k;
            }

            else
                monster.first = 0;
            
            // cout << "Fight ends\t" << monster.first << " " << monster.second << "\n";

            if (monster.first > 0)
                pq.push(monster);
            else
                cout << monster.second << " ";
        }

        cout << "\n";
    }

    return 0;
}
