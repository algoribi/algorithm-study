// BOJ_1743_음식물 피하기

#include <iostream>
#include <vector>

using namespace std;

int n, m, num, counter = 0, maxx = 0, sp[105][105], visit[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    counter++;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx > 0 && newy > 0 && newx < n + 1 && newy < m + 1 && visit[newx][newy] == 0 && sp[newx][newy] == 1)
            dfs(newx, newy);
        else
            continue;
    }
    return;
}

int main() {
    cin >> n >> m >> num;
    for (int i = 0; i < num; i++) {
        int u, v;
        cin >> u >> v;
        sp[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sp[i][j] == 1 && visit[i][j] == 0) {
                counter = 0;
                dfs(i, j);
                if (counter > maxx)
                    maxx = counter;
            }
        }
    }
    cout << maxx << '\n';
    return 0;
}
