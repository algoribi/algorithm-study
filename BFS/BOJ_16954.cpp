// algorithm study
// BOJ_16954_움직이는 미로 탈출

#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct go {
    int x;
    int y;
    int time;
};

main() {
    char block[10][10][10];
    int visit[10][10][10] = {0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> block[0][i][j];
        }
    }
    queue<go> q;
    q.push({7, 0, 0});
    visit[0][7][0] = 1;
    int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int chk = 0, count_time = 0;
    while (!q.empty()) {
        go temp;
        temp = q.front();
        q.pop();
        if (temp.time != count_time) {
            count_time = temp.time;
            for (int i = 7; i >= 0; i--) {
                for (int j = 7; j >= 0; j--) {
                    if (i == 0)
                        block[count_time][i][j] = '.';
                    else
                        block[count_time][i][j] = block[count_time - 1][i - 1][j];
                }
            }
        }
        if (block[temp.time][temp.x][temp.y] != '.')
            continue;
        if (temp.x == 0 && temp.y == 7) {
            chk = 1;
            break;
        }
        for (int i = 0; i < 9; i++) {
            int newx = temp.x + dx[i];
            int newy = temp.y + dy[i];

            if (newx < 0 || newx >= 8 || newy < 0 || newy >= 8 || block[temp.time][newx][newy] == '#' || visit[temp.time + 1][newx][newy] == 1)
                continue;
            if (temp.time >= 8)
                temp.time -= 1;
            q.push({newx, newy, temp.time + 1});
            visit[temp.time + 1][newx][newy] = 1;
        }
    }
    if (chk == 0)
        cout << 0;
    else
        cout << 1;
    return 0;
}