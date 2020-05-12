// BOJ_11724_연결 요소의 개수

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[10001];
int visit[10001], v_count = 0;

void dfs(int here) {
    visit[here] = 1;
    for (int i = 0; i < g[here].size(); i++) {
        int there = g[here][i];
        if (visit[there] == 0)
            dfs(there);
    }
}

void dfsAll(int n) {
    for (int i = 0; i <= n; i++) {
        if (visit[i] == 0) {
            v_count++;
            dfs(i);
        }
    }
}

void addEdge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int main() {
    int n, m, u, v;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }

    dfsAll(n);

    cout << v_count - 1 << "\n";

    return 0;
}