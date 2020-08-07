#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct city {
    int now;
    int cost;
};

int main() {
    int n, m, a, b, c, start, end;
    cin >> n >> m;
    vector<pair<int, int>> map[1010];
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    cin >> start >> end;

    int weight[1010];
    for (int i = 0; i < 1010; i++) {
        weight[i] = -1;
    }
    weight[start] = 0;
    vector<int> visit[1010];
    visit[start].push_back(start);
    queue<city> pq;
    pq.push({start, 0});
    while (!pq.empty()) {
        city top = pq.front();
        pq.pop();
        for (int i = 0; i < map[top.now].size(); i++) {
            if (weight[map[top.now][i].first] == -1 || weight[map[top.now][i].first] > top.cost + map[top.now][i].second) {
                visit[map[top.now][i].first].clear();
                visit[map[top.now][i].first].assign(visit[top.now].begin(), visit[top.now].end());
                visit[map[top.now][i].first].push_back(map[top.now][i].first);
                weight[map[top.now][i].first] = top.cost + map[top.now][i].second;
                pq.push({map[top.now][i].first, top.cost + map[top.now][i].second});
            }
        }
    }
    cout << weight[end] << "\n"
         << visit[end].size() << "\n";
    for (int i = 0; i < visit[end].size(); i++) {
        cout << visit[end][i] << " ";
    }
    return 0;
}