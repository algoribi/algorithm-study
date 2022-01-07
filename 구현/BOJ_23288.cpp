#include <iostream>
#include <queue>

using namespace std;

int n, m, k, map[25][25], ans, direc = 3, x = 1, y = 1;
int dice[6] = {1, 6, 4, 3, 5, 2}; // 0. 위, 1. 아래, 2. 좌, 3. 우, 4. 앞, 5. 뒤
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void turn_dice() {
    int newx = x + dx[direc];
    int newy = y + dy[direc];
    if (newx <= 0 || newx > n || newy <= 0 || newy > m) { // 조건 1
        if (direc == 0)
            direc = 1;
        else if (direc == 1)
            direc = 0;
        else if (direc == 2)
            direc = 3;
        else 
            direc = 2;
        turn_dice();
        return;
    }
    x = newx;
    y = newy;

    // 주사위 돌려주기
    int d0 = dice[0], d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5];
    if(direc == 0) {
        dice[0] = d4;
        dice[4] = d1;
        dice[1] = d5;
        dice[5] = d0;
    } else if (direc == 1) {
        dice[0] = d5;
        dice[4] = d0;
        dice[1] = d4;
        dice[5] = d1;
    } else if (direc == 2) {
        dice[2] = d0;
        dice[0] = d3;
        dice[3] = d1;
        dice[1] = d2;
    } else {
        dice[2] = d1;
        dice[0] = d2;
        dice[3] = d0;
        dice[1] = d3;
    }

    // 방향 결정 // 조건 3
    if (dice[1] > map[x][y]) {
        if (direc == 0) 
            direc = 3;
        else if (direc == 1)
            direc = 2;
        else if (direc == 2)
            direc = 0;
        else
            direc = 1;
    } else if (dice[1] < map[x][y]) {
        if (direc == 0) 
            direc = 2;
        else if (direc == 1) 
            direc = 3;
        else if (direc == 2)
            direc = 1;
        else 
            direc = 0;
    }
    return;
}

void score() {
    queue<pair<int, int>> q;
    bool visit[25][25] = {0};
    q.push({x, y});
    visit[x][y] = 1;
    int fl = map[x][y], counter = 1;
    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = f.first + dx[i];
            int newy = f.second + dy[i];
            if (newx <= 0 || newx > n || newy <= 0 || newy > m || visit[newx][newy] == 1 || map[newx][newy] != fl)
                continue;
            q.push({newx, newy});
            visit[newx][newy] = 1;
            counter++;
        }
    }
    ans += counter * fl;
    return;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < k; i++) {
        turn_dice();
        score();
    }

    cout << ans;

    return 0;
}