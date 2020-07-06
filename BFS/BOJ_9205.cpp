#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
    int testcase, n;
    pair<int, int> home, rock;
    vector<pair<int, int>> conveni;
    cin >> testcase;
    for (int t = 0; t < testcase; t++) {
        cin >> n >> home.first >> home.second;
        conveni.clear();
        for (int i = 0; i < n; i++) {
            pair<int, int> temp;
            cin >> temp.first >> temp.second;
            conveni.push_back(temp);
        }
        cin >> rock.first >> rock.second;
        if (abs(home.first - rock.first) + abs(home.second - rock.second) <= 1000) {
            cout << "happy" << endl;
            continue;
        }
        int visit[110] = {0};
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (abs(conveni[i].first - rock.first) + abs(conveni[i].second - rock.second) <= 1000)
                q.push(i);
        }
        int fl = 0;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            visit[temp] = 1;
            if (abs(conveni[temp].first - home.first) + abs(conveni[temp].second - home.second) <= 1000) {
                cout << "happy" << endl;
                fl = 1;
                break;
            }
            for (int i = 0; i < n; i++) {
                if (i == temp || visit[i] == 1)
                    continue;
                if (abs(conveni[i].first - conveni[temp].first) + abs(conveni[i].second - conveni[temp].second) <= 1000)
                    q.push(i);
            }
        }
        if (fl == 0)
            cout << "sad" << endl;
    }
}