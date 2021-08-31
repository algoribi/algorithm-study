#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

struct qu {
    int x, y, d, t;
};

int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
int visit[110][110][6], board_size;
queue<qu> q;

bool chk(int x, int y) {
    if (x < 0 || x >= board_size || y < 0 || y >= board_size)
        return false;
    return true;
}

void turn(int x, int y, int d, int t) {
    if (visit[x][y][d] == 0) {
        visit[x][y][d] = 1;
        q.push({ x, y, d, t + 1 });
    }
}

int solution(vector<vector<int>> board) {
    board_size = board.size();
    q.push({ 0, 0, 3, 0 });
    visit[0][0][3] = 1;
    while (!q.empty()) {
        qu f = q.front();
        q.pop();

        if ((f.x == board_size - 1 && f.y == board_size - 1) || (f.x + dx[f.d] == board_size - 1 && f.y + dy[f.d] == board_size - 1))
            return f.t;

        for (int i = 0; i < 4; i++) {  // 상, 하, 좌, 우
            int newx = f.x + dx[i];
            int newy = f.y + dy[i];
            if (!(chk(newx, newy) && chk(newx + dx[f.d], newy + dy[f.d])) || board[newx][newy] == 1 || board[newx + dx[f.d]][newy + dy[f.d]] == 1 || visit[newx][newy][f.d] == 1)
                continue;
            q.push({ newx, newy, f.d, f.t + 1 });
            visit[newx][newy][f.d] = 1;
        }
        if (f.d == 2 || f.d == 3) {  // 가로
            int newx = f.x + dx[0];
            int newy = f.y + dy[0];
            if ((chk(newx, newy) && chk(newx + dx[f.d], newy + dy[f.d])) && board[newx][newy] == 0 && board[newx + dx[f.d]][newy + dy[f.d]] == 0) {  // 위로 90
                turn(f.x, f.y, 0, f.t);
                turn(newx + dx[f.d], newy + dy[f.d], 1, f.t);
            }
            newx = f.x + dx[1];
            newy = f.y + dy[1];
            if ((chk(newx, newy) && chk(newx + dx[f.d], newy + dy[f.d])) && board[newx][newy] == 0 && board[newx + dx[f.d]][newy + dy[f.d]] == 0) {  // 아래로 90
                turn(f.x, f.y, 1, f.t);
                turn(newx + dx[f.d], newy + dy[f.d], 0, f.t);
            }
        }
        else {  // 세로
            int newx = f.x + dx[2];
            int newy = f.y + dy[2];
            if ((chk(newx, newy) && chk(newx + dx[f.d], newy + dy[f.d])) && board[newx][newy] == 0 && board[newx + dx[f.d]][newy + dy[f.d]] == 0) {  // 좌로 90
                turn(f.x, f.y, 2, f.t);
                turn(newx + dx[f.d], newy + dy[f.d], 3, f.t);
            }
            newx = f.x + dx[3];
            newy = f.y + dy[3];
            if ((chk(newx, newy) && chk(newx + dx[f.d], newy + dy[f.d])) && board[newx][newy] == 0 && board[newx + dx[f.d]][newy + dy[f.d]] == 0) {  // 우로 90
                turn(f.x, f.y, 3, f.t);
                turn(newx + dx[f.d], newy + dy[f.d], 2, f.t);
            }
        }
    }
}