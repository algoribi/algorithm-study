#include <iostream>
#include <queue>

using namespace std;

int n, m, h, w, sr, sc, fr, fc;
bool map[1010][1010];
int visit[1010][1010], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            visit[i][j] = -1;
        }
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                for (int k = i; k > i - h; k--) {
                    for (int l = j; l > j - w; l--) {
                        if (l < 1 || k < 1)
                            continue;
                        visit[k][l] = -2;
                    }
                }
            }
        }
    }
    if (visit[fr][fc] == -2) {
        cout << -1;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({sr, sc});
    visit[sr][sc] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first == fr && p.second == fc)
            break;

        for (int i = 0; i < 4; i++) {
            int newx = p.first + dx[i];
            int newy = p.second + dy[i];
            if (newx < 1 || newy < 1 || newx + h - 1 > n || newy + w - 1 > m || visit[newx][newy] != -1)
                continue;
            q.push({newx, newy});
            visit[newx][newy] = visit[p.first][p.second] + 1;
        }
    }
    cout << visit[fr][fc];
    return 0;
}