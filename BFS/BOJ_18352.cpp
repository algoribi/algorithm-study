#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define endl "\n"

using namespace std;

int N, M, K, X, visit[300010] = {0};
vector<int> map[300010];
set<int> ans;

int main() {
    cin >> N >> M >> K >> X;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a].push_back(b);
    }

    queue<pair<int, int>> q;
    q.push({X, 0});
    visit[X] = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < map[p.first].size(); i++) {
            if (visit[map[p.first][i]] != 0 || p.second >= K)
                continue;
            if (p.second + 1 == K)
                ans.insert(map[p.first][i]);
            q.push({map[p.first][i], p.second + 1});
            visit[map[p.first][i]] = 1;
        }
    }
    if (ans.size() == 0)
        cout << -1;
    else {
        for (auto i : ans)
            cout << i << endl;
    }
    return 0;
}