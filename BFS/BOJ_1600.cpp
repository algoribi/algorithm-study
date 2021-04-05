#include <string.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct horse {
    int x;
    int y;
    int kcounter = 0;
};

int visit[210][210][32] = {-1};

int main() {
    int k, w, h, map[210][210];
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> map[i][j];
    }

    int horse_x[] = {-2, -1, 2, 1, -2, -1, 2, 1}, horse_y[] = {-1, -2, -1, -2, 1, 2, 1, 2}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    memset(visit, -1, sizeof(visit));

    queue<horse> q;
    q.push({0, 0, 0});
    visit[0][0][0] = 0;

    while (!q.empty()) {
        horse f = q.front();
        q.pop();
        if (f.x == h - 1 && f.y == w - 1)
            continue;
        if (f.kcounter < k) {
            for (int i = 0; i < 8; i++) {
                int newx = f.x + horse_x[i];
                int newy = f.y + horse_y[i];
                if (newx < 0 || newx >= h || newy < 0 || newy >= w || map[newx][newy] == 1 || (visit[newx][newy][f.kcounter + 1] != -1 && visit[newx][newy][f.kcounter + 1] <= visit[f.x][f.y][f.kcounter] + 1))
                    continue;
                q.push({newx, newy, f.kcounter + 1});
                visit[newx][newy][f.kcounter + 1] = visit[f.x][f.y][f.kcounter] + 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int newx = f.x + dx[i];
            int newy = f.y + dy[i];
            if (newx < 0 || newx >= h || newy < 0 || newy >= w || map[newx][newy] == 1 || (visit[newx][newy][f.kcounter] != -1 && visit[newx][newy][f.kcounter] <= visit[f.x][f.y][f.kcounter] + 1))
                continue;
            q.push({newx, newy, f.kcounter});
            visit[newx][newy][f.kcounter] = visit[f.x][f.y][f.kcounter] + 1;
        }
    }

    int ans = -1;
    for (int i = 0; i <= k; i++) {
        if (ans == -1 || (visit[h - 1][w - 1][i] != -1 && ans > visit[h - 1][w - 1][i]))
            ans = visit[h - 1][w - 1][i];
    }
    cout << ans;

    return 0;
}