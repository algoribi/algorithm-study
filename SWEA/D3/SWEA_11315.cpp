#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

struct qnum {
    int x, y, go, counter;
};

int main() {
    int test_case, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        int n, chk = 0;
        char map[25][25];
        cin >> n;
        queue<qnum> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'o') {
                    q.push({i, j, 0, 1});
                    q.push({i, j, 1, 1});
                    q.push({i, j, 2, 1});
                    q.push({i, j, 3, 1});
                    q.push({i, j, 4, 1});
                    q.push({i, j, 5, 1});
                    q.push({i, j, 6, 1});
                    q.push({i, j, 7, 1});
                }
            }
        }
        while (!q.empty()) {
            qnum f = q.front();
            q.pop();
            if (f.counter >= 5) {
                chk = 1;
                break;
            }
            int newx = f.x + dx[f.go];
            int newy = f.y + dy[f.go];
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && map[newx][newy] == 'o')
                q.push({newx, newy, f.go, f.counter + 1});
        }
        cout << "#" << t << " ";
        if (chk == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}