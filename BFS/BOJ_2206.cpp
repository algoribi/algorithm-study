#include <algorithm>
#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

struct go {
    int x, y, chk, counter;
};
int m, n, visit[1010][1010][2] = { 0 }, dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
string map[1010];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    queue<go> q;
    q.push({ 0, 0, 0, 1 });
    visit[0][0][0] = 1;
    while (!q.empty()) {
        go g = q.front();
        q.pop();
        if (g.x == n - 1 && g.y == m - 1) {
            cout << visit[g.x][g.y][g.chk];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int newx = g.x + dx[i];
            int newy = g.y + dy[i];
            if (newx < 0 || newy < 0 || newx >= n || newy >= m)
                continue;
            if (map[newx][newy] == '1' && g.chk == 0 && visit[newx][newy][1] == 0) {
                q.push({ newx, newy, 1, g.counter + 1 });
                visit[newx][newy][1] = g.counter + 1;
            }
            else if (map[newx][newy] == '0' && visit[newx][newy][g.chk] == 0) {
                q.push({ newx, newy, g.chk, g.counter + 1 });
                visit[newx][newy][g.chk] = g.counter + 1;
            }
        }
    }
    if (visit[n - 1][m - 1][0] == 0 && visit[n - 1][m - 1][1] == 0)
        cout << "-1";

    return 0;
}