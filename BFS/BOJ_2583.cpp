// BOJ_2583_영역 구하기

#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

vector<int> save;
int blank[105][105], m, n, k, counter = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    blank[x][y] = 1;
    counter++;
    for (int i = 0; i < 4; i++) {
        int rex = x + dx[i];
        int rey = y + dy[i];
        if (blank[rex][rey] != 1 && rex >= 0 && rex < n && rey >= 0 && rey < m)
            dfs(rex, rey);
        else
            continue;
    }
    return;
}

void dfs_all_search() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blank[i][j] != 1) {
                counter = 0;
                dfs(i, j);
                save.push_back(counter);
            } else
                continue;
        }
    }
    return;
}

int main() {
    cin >> m >> n >> k;
    for (int num = 0; num < k; num++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < c; i++) {
            for (int j = b; j < d; j++) {
                blank[i][j] = 1;
            }
        }
    }

    dfs_all_search();
    sort(save.begin(), save.end());

    cout << save.size() << endl;
    for (int i = 0; i < save.size(); i++) {
        cout << save[i] << " ";
    }
    cout << endl;

    return 0;
}