// BOJ_11724_연결 요소의 개수

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[10001];
int visit[10001], v_count = 0;

void dfs(int num) {
    visit[num] = 1;
    for (int i = 0; i < g[num].size(); i++) {
        if (visit[g[num][i]] == 0)
            dfs(g[num][i]);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i <= n; i++) {
        if (visit[i] == 0) {
            v_count++;
            dfs(i);
        }
    }
    cout << v_count - 1 << '\n';

    return 0;
}