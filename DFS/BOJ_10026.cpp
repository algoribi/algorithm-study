// BOJ_10026_적록색약

#include <iostream>

using namespace std;

char sp[105][105];
int visit[105][105], n, counter;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    char chk = sp[x][y];
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && visit[newx][newy] == 0 && sp[newx][newy] == chk)
            dfs(newx, newy);
        else
            continue;
    }
    return;
}
void dfs2(int x, int y) {
    visit[x][y] = 2;
    char chk = sp[x][y];
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && visit[newx][newy] < 2) {
            if ((chk == 'R' || chk == 'G') && (sp[newx][newy] == 'R' || sp[newx][newy] == 'G'))
                dfs2(newx, newy);
            else if (sp[newx][newy] == chk)
                dfs2(newx, newy);
        } else
            continue;
    }
    return;
}
void dfsAll(int nn) {
    counter = 0;
    if (nn == 1) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (visit[a][b] == 0) {
                    dfs(a, b);
                    counter++;
                }
            }
        }
    } else if (nn = 2) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (visit[a][b] < 2) {
                    dfs2(a, b);
                    counter++;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char col;
            cin >> col;
            sp[i][j] = col;
        }
    }
    dfsAll(1);
    cout << counter << ' ';
    dfsAll(2);
    cout << counter << '\n';
    return 0;
}