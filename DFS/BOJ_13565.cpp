// algorithm study
// BOJ_13565_침투

#include <iostream>
#include <vector>

using namespace std;

int m, n, visit[1010][1010] = {0}, chk = 0;
char arr[1010][1010];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    if (x == m - 1) {
        chk = 1;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= m || newy < 0 || newy >= n || visit[newx][newy] == 1 || arr[newx][newy] == '1')
            continue;
        dfs(newx, newy);
        if (chk == 1)
            return;
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[0][i] == '0' && visit[0][i] == 0) {
            dfs(0, i);
            if (chk == 1) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}