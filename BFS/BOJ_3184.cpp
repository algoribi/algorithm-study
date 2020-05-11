// algorithm study
// BOJ_3184_양

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int r, c, an_s = 0, an_w = 0, visit[270][270] = {0};
    cin >> r >> c;
    char map[270][270];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sheep = 0, wolf = 0, chk = 0;
            if (visit[i][j] == 0 && map[i][j] != '#') {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = 1;
                while (!q.empty()) {
                    pair<int, int> f = q.front();
                    q.pop();
                    if (map[f.first][f.second] == 'o')
                        sheep++;
                    else if (map[f.first][f.second] == 'v')
                        wolf++;

                    for (int k = 0; k < 4; k++) {
                        int newx = f.first + dx[k];
                        int newy = f.second + dy[k];
                        if (newx < 0 || newx >= r || newy < 0 || newy >= c)
                            continue;
                        if (map[newx][newy] != '#' && visit[newx][newy] != 1) {
                            q.push(make_pair(newx, newy));
                            visit[newx][newy] = 1;
                        }
                    }
                }
                if (sheep > wolf)
                    an_s += sheep;
                else
                    an_w += wolf;
            }
        }
    }
    cout << an_s << " " << an_w;
    return 0;
}