// algorithm study
// BOJ_1987_알파벳

#include <iostream>

using namespace std;

char map[25][25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visit[30] = {0}, r, c, add = 0, m_ax = 0;

void dfs(int x, int y) {
    visit[map[x][y] - 65] = 1;
    add++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
            if (visit[map[nx][ny] - 65] == 0) {
                dfs(nx, ny);
                visit[map[nx][ny] - 65] = 0;
                add--;
            }
        }
    }
    if (add > m_ax)
        m_ax = add;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    dfs(0, 0);

    cout << m_ax;
    return 0;
}