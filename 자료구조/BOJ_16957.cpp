// algorithm study
// BOJ_16957_체스판 위의 공

#include <iostream>
using namespace std;

int r, c, chess[510][510], visit[510][510];
pair<int, int> save[510][510];
int dx[9] = {0, -1, 1, -1, 1, 0, 0, -1, 1};
int dy[9] = {0, -1, 1, 1, -1, -1, 1, 0, 0};
int findx = 510, findy = 510;

void dfs(int x, int y) {
    if (save[x][y].first < 510) {
        findx = save[x][y].first;
        findy = save[x][y].second;
        visit[findx][findy]++;
        return;
    }
    int minx = 509, miny = 509;
    for (int i = 0; i < 10; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= r || newy < 0 || newy >= c)
            continue;
        if (chess[newx][newy] < chess[minx][miny]) {
            minx = newx;
            miny = newy;
        }
    }
    if (minx == x && miny == y) {
        findx = x;
        findy = y;
        save[x][y] = make_pair(findx, findy);
        visit[x][y]++;
    } else {
        dfs(minx, miny);
        save[x][y] = make_pair(findx, findy);
    }
}
int main() {
    chess[509][509] = 300010;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> chess[i][j];
            visit[i][j] = 0;
            save[i][j] = make_pair(510, 510);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (save[i][j].first < 510) {
                visit[save[i][j].first][save[i][j].second]++;
                continue;
            }
            dfs(i, j);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}