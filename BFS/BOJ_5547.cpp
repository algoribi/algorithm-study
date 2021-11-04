#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

struct q_num {
    int x, y;
};

int main() {
    int w, h, answer = 0, map[105][105] = {0}, visit[105][105] = {0}, dx[] = {-1, -1, 0, 0, 1, 1}, dy[] = {0, 1, -1, 1, 0, 1};
    cin >> w >> h;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cin >> map[i][j];
    }

    queue<q_num> q;
    q.push({0, 0});
    visit[0][0] = 1;

    while (!q.empty()) {
        q_num f = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int newx = f.x + dx[i];
            int newy = f.y + dy[i];
            if (f.x % 2 == 0 && (i == 0 || i == 1 || i == 4 || i == 5))
                newy -= 1;
            if (newx < 0 || newy < 0 || newx > h + 1 || newy > w + 1 || map[newx][newy] == 1 || visit[newx][newy] == 1)
                continue;
            visit[newx][newy] = 1;
            q.push({newx, newy});
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (visit[i][j] != 0)
                continue;
            int counter = 0;
            for (int k = 0; k < 6; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if (i % 2 == 0 && (k == 0 || k == 1 || k == 4 || k == 5))
                    newy -= 1;
                if (visit[newx][newy] == 1)
                    counter++;
            }
            answer += counter;
        }
    }
    cout << answer;

    return 0;
}