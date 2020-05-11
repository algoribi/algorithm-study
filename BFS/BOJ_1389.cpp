// BOJ_1389_케빈 베이컨의 6단계 법칙

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m, deep, an[105][105], chk[105][105];
    vector<int> friends[105];
    queue<int> q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        deep = 0;
        an[i][i] = deep;
        chk[i][i] = 1;
        q.push(i);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int j = 0; j < friends[temp].size(); j++) {
                int next = friends[temp][j];
                if (chk[i][next] == 0) {
                    q.push(next);
                    chk[i][next] = 1;
                    an[i][next] = an[i][temp] + 1;
                }
            }
        }
        an[i][104] = 0;
        for (int b = 1; b <= n; b++) {
            an[i][104] = an[i][104] + an[i][b];
        }
    }
    pair<int, int> p;
    p.first = 1;
    p.second = an[1][104];
    for (int k = 2; k <= n; k++) {
        if (an[k][104] < p.second) {
            p.first = k;
            p.second = an[k][104];
        }
    }
    cout << p.first << '\n';
    return 0;
}