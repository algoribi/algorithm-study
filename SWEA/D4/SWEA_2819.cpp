// algorithm study
// SWEA_[D4]2819_격자판의 숫자 이어 붙이기

#include <iostream>
#include <set>

using namespace std;

char arr[5][5];
set<string> s;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y, string num) {
    if (num.size() == 7) {
        if (s.find(num) == s.end())
            s.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx > 3 || newy < 0 || newy > 3)
            continue;
        num.push_back(arr[newx][newy]);
        dfs(newx, newy, num);
        num.erase(num.size() - 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(i, j, "");
            }
        }
        cout << "#" << c + 1 << " " << s.size() << "\n";
        s.clear();
    }
    return 0;
}