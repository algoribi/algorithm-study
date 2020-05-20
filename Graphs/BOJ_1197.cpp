// BOJ_1197_최소 스패닝 트리

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > v[10001];
priority_queue<pair<int, int> > q;
bool chk[10001];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    chk[1] = true;
    for (int j = 0; j < v[1].size(); j++) {
        q.push(make_pair(-v[1][j].second, v[1][j].first));
    }
    int ans = 0;
    while (!q.empty()) {
        auto n = q.top();
        q.pop();
        if (!chk[n.second]) {
            chk[n.second] = true;
            ans += -n.first;
            for (int k = 0; k < v[n.second].size(); k++) {
                q.push(make_pair(-v[n.second][k].second, v[n.second][k].first));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}