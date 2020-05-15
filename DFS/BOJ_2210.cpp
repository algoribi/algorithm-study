// algorithm study
// BOJ_2210_숫자판 점프

#include <iostream>
#include <map>

using namespace std;

char digit[7][7];
map<string, int> m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int a, int b, string s) {
    if (s.size() == 6) {
        if (m.find(s) == m.end())
            m.insert(make_pair(s, 1));
        return;
    }
    for (int i = 0; i < 4; i++) {
        int re_x = a + dx[i];
        int re_y = b + dy[i];
        if (re_x < 0 || re_x > 4 || re_y < 0 || re_y > 4)
            continue;
        else
            dfs(re_x, re_y, s + digit[re_x][re_y]);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> digit[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string t = "";
            t += digit[i][j];
            dfs(i, j, t);
        }
    }
    cout << m.size();
    return 0;
}