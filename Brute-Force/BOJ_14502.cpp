#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, map[10][10], bfsmap[10][10], answer = -1;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
vector<pair<int, int>> virus;

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
        q.push({virus[i].first, virus[i].second});

    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newx = f.first + dx[i];
            int newy = f.second + dy[i];

            if (newx >= 0 && newx < n && newy >= 0 && newy < m && bfsmap[newx][newy] == 0) {
                bfsmap[newx][newy] = 2;
                q.push({newx, newy});
            }
        }
    }
}
void wall(int counter) {
    if (counter == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                bfsmap[i][j] = map[i][j];
        }
        bfs();
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bfsmap[i][j] == 0)
                    num++;
            }
        }
        if (num > answer)
            answer = num;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                wall(counter + 1);
                map[i][j] = 0;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({i, j});
        }
    }
    wall(0);
    cout << answer;
    return 0;
}