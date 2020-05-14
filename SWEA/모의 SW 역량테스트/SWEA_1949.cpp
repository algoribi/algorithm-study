// algorithm study
// SWEA_[모의 SW 역량테스트]1949_등산로 조성

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t, n, k, max_num = 0, counter = 0, answer = 0, chk = 0;
int map[10][10], visit[10][10];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> h;

void dfs(int x, int y) {
    counter++;
    visit[x][y] = 1;
    int go_chk = 0;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= n || visit[newx][newy] == 1)
            continue;
        else if (map[newx][newy] >= map[x][y] && map[newx][newy] - k < map[x][y] && chk == 0) {
            chk = 1;
            go_chk = 1;
            int temp = map[newx][newy];
            map[newx][newy] = map[x][y] - 1;
            dfs(newx, newy);
            chk = 0;
            map[newx][newy] = temp;
        } else if (map[newx][newy] < map[x][y]) {
            go_chk = 1;
            dfs(newx, newy);
        }
    }
    if (go_chk == 0) {
        if (answer < counter)
            answer = counter;
    }
    visit[x][y] = 0;
    counter--;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                visit[j][l] = 0;
                cin >> map[j][l];
                if (max_num < map[j][l]) {
                    h.clear();
                    max_num = map[j][l];
                    h.push_back(make_pair(j, l));
                } else if (max_num == map[j][l])
                    h.push_back(make_pair(j, l));
            }
        }
        for (int j = 0; j < h.size(); j++) {
            dfs(h[j].first, h[j].second);
        }
        cout << "#" << i + 1 << " " << answer << "\n";
        answer = counter = max_num = chk = 0;
    }
    return 0;
}