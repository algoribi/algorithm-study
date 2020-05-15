// algorithm study
// BOJ_1260_DFS와 BFS

#include <iostream>
#include <queue>

using namespace std;

int n, m, v, c = 0;
int b[1010][1010];
int dfs_c[1010] = {0}, bfs_c[1010] = {0};
queue<int> q;

void dfs(int num) {
    c++;
    dfs_c[num] = 1;
    cout << num << " ";
    if (c == n) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[num][i] == 1 && dfs_c[i] != 1) {
            dfs(i);
        }
    }
}

void bfs(int num) {
    bfs_c[num] = 1;
    q.push(num);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 1; i <= n; i++) {
            if (b[node][i] == 1 && bfs_c[i] == 0) {
                bfs_c[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b[x][y] = 1;
        b[y][x] = 1;
    }

    dfs(v);
    cout << "\n";
    c = 0;
    bfs(v);

    return 0;
}