#include <iostream>

using namespace std;

int m, n, map[505][505], visit[505][505], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int dfs(int a, int b) {
    if (a == m - 1 && b == n - 1)
        return 1;
    else if (visit[a][b] == -1) {
        visit[a][b] = 0;
        for (int i = 0; i < 4; i++) {
            int newx = a + dx[i];
            int newy = b + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && map[newx][newy] < map[a][b])
                visit[a][b] += dfs(newx, newy);
        }
    }
    return visit[a][b];
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            visit[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
    return 0;
}