
// algorithm study
// BOJ_2644_촌수계산

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<int> p[110];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    queue<int> q;
    q.push(a);
    int visit[100] = {0};
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        if (f == b)
            break;
        for (int i = 0; i < p[f].size(); i++) {
            if (visit[p[f][i]] > 0)
                continue;
            q.push(p[f][i]);
            visit[p[f][i]] = visit[f] + 1;
        }
    }
    if (visit[b] == 0)
        cout << -1;
    else
        cout << visit[b];
    return 0;
}