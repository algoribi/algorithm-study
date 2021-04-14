#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct bfs {
    int x;
    int y;
    string strk;
};

int main() {
    int n, m, k;
    char board[15][15];
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    queue<bfs> q;
    map<string, int> save;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            string s = "";
            s += board[i][j];
            q.push({i, j, s});
            if (save.find(s) != save.end())
                save.find(s)->second++;
            else
                save.insert({s, 1});
        }
    }
    while (!q.empty()) {
        bfs f = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int newx = f.x + dx[i];
            int newy = f.y + dy[i];
            if (newx < 0)
                newx = n - 1;
            else if (newx >= n)
                newx = 0;
            if (newy < 0)
                newy = m - 1;
            else if (newy >= m)
                newy = 0;

            string re_s = f.strk + board[newx][newy];
            if (save.find(re_s) != save.end())
                save.find(re_s)->second++;
            else
                save.insert({re_s, 1});

            if (re_s.size() < 5)
                q.push({newx, newy, re_s});
        }
    }

    for (int i = 0; i < k; i++) {
        string temp;
        cin >> temp;
        if (save.find(temp) == save.end())
            cout << 0 << "\n";
        else
            cout << save.find(temp)->second << "\n";
    }

    return 0;
}