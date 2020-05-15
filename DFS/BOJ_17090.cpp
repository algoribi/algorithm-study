// algorithm study
// BOJ_17090_미로 탈출하기

#include <iostream>
#include <vector>

using namespace std;
int n, m, visit[510][510] = {0}, dp[510][510] = {0}, answer = 0;
char map[510][510];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    visit[i][j] = 1;
    int rx, ry;
    if (map[i][j] == 'D') {
        rx = i + dx[0];
        ry = j + dy[0];
    } else if (map[i][j] == 'U') {
        rx = i + dx[1];
        ry = j + dy[1];
    } else if (map[i][j] == 'R') {
        rx = i + dx[2];
        ry = j + dy[2];
    } else if (map[i][j] == 'L') {
        rx = i + dx[3];
        ry = j + dy[3];
    }

    if (visit[rx][ry] == 1) {
        dp[i][j] = 2;
    }
    if (rx < 0 || rx >= n || ry < 0 || ry >= m) {
        dp[i][j] = 1;
        answer++;
        return;
    } else if (dp[rx][ry] == 1) {
        dp[i][j] = 1;
        answer++;
        return;
    } else if (dp[rx][ry] == 2) {
        dp[i][j] = 2;
        return;
    } else {
        dfs(rx, ry);
        visit[rx][ry] = 0;
        if (dp[rx][ry] == 1)
            dp[i][j] = 1;
        else if (dp[rx][ry] == 2)
            dp[i][j] = 2;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == 2)
                continue;
            dfs(i, j);
            visit[i][j] = 0;
        }
    }

    cout << answer;
    return 0;
}