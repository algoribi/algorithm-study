#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool go_x(int x1, int y1, int x2, int y2, vector<string> board) {
    char go = '+';
    if (x1 == x2)
        return true;
    else if (x1 > x2)
        go = '-';

    while (1) {
        if (go == '-')
            x1--;
        else
            x1++;
        if (board[x1][y1] != '.') {
            if (board[x1][y1] == board[x2][y2])
                return true;
            else
                return false;
        } else if (board[x1][y1] == '.' && x1 == x2)
            return true;
    }
}

bool go_y(int x1, int y1, int x2, int y2, vector<string> board) {
    char go = '+';
    if (y1 == y2)
        return true;
    else if (y1 > y2)
        go = '-';

    while (1) {
        if (go == '-')
            y1--;
        else
            y1++;
        if (board[x1][y1] != '.') {
            if (board[x1][y1] == board[x2][y2])
                return true;
            else
                return false;
        } else if (board[x1][y1] == '.' && y1 == y2)
            return true;
    }
}
string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<pair<int, int>> save[30];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                save[board[i][j] - 'A'].push_back(make_pair(i, j));
        }
    }
    while (1) {
        int chk = 0;
        for (int i = 0; i < 26; i++) {
            if (save[i].size() == 0)
                continue;
            chk = -1;
            if (go_x(save[i][0].first, save[i][0].second, save[i][1].first, save[i][1].second, board) && go_y(save[i][1].first, save[i][0].second, save[i][1].first, save[i][1].second, board)) {
                chk = 1;
                answer.push_back(board[save[i][0].first][save[i][0].second]);
                board[save[i][0].first][save[i][0].second] = '.';
                board[save[i][1].first][save[i][1].second] = '.';
                save[i].clear();
                break;
            }
            if (go_x(save[i][1].first, save[i][1].second, save[i][0].first, save[i][0].second, board) && go_y(save[i][0].first, save[i][1].second, save[i][0].first, save[i][0].second, board)) {
                chk = 1;
                answer.push_back(board[save[i][0].first][save[i][0].second]);
                board[save[i][0].first][save[i][0].second] = '.';
                board[save[i][1].first][save[i][1].second] = '.';
                save[i].clear();
                break;
            }
        }
        if (chk == 0)
            return answer;
        else if (chk == -1)
            return "IMPOSSIBLE";
    }
    return answer;
}