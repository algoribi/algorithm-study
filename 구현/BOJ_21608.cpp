#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, st[405][5], ans[25][25] = { 0 }, dx[] = { 0, -1, 0, 1 }, dy[] = { -1, 0, 1, 0 };
    cin >> n;
    for (int num = 0; num < n * n; num++) {
        cin >> k;
        cin >> st[k][0] >> st[k][1] >> st[k][2] >> st[k][3];
        pair <int, int> p, point; // 인접한 칸 중 좋아하는 학생 수, 인접한 칸 중 빈칸의 수
        p.first = -1;
        p.second = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] != 0)
                    continue;
                int friend_counter = 0, empty_counter = 0;
                for (int l = 0; l < 4; l++) {
                    int newx = i + dx[l];
                    int newy = j + dy[l];
                    if (newx < 0 || newy < 0 || newx >= n || newy >= n)
                        continue;
                    if (ans[newx][newy] == 0)
                        empty_counter++;
                    else if (ans[newx][newy] == st[k][0])
                        friend_counter++;
                    else if (ans[newx][newy] == st[k][1])
                        friend_counter++;
                    else if (ans[newx][newy] == st[k][2])
                        friend_counter++;
                    else if (ans[newx][newy] == st[k][3])
                        friend_counter++;
                }
                if (friend_counter > p.first) {
                    p.first = friend_counter;
                    p.second = empty_counter;
                    point.first = i;
                    point.second = j;
                }
                else if (friend_counter == p.first && empty_counter > p.second) {
                    p.first = friend_counter;
                    p.second = empty_counter;
                    point.first = i;
                    point.second = j;
                }
            }
        }
        ans[point.first][point.second] = k;
    }
    int ans_num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int add = 0;
            for (int k = 0; k < 4; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if (newx < 0 || newy < 0 || newx >= n || newy >= n)
                    continue;
                for (int l = 0; l < 4; l++) {
                    if (st[ans[i][j]][l] == ans[newx][newy])
                        add++;
                }
            }
            if (add == 1)
                ans_num += 1;
            else if (add == 2)
                ans_num += 10;
            else if (add == 3)
                ans_num += 100;
            else if (add == 4)
                ans_num += 1000;
        }
    }
    cout << ans_num;
}