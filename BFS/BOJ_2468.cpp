// BOJ_2468_안전 영역

#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

vector<int> save;
int area[105][105], visit[105][105], n, s = 0, b = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int rex = x + dx[i];
        int rey = y + dy[i];
        if (visit[rex][rey] != 1 && rex >= 0 && rex < n && rey >= 0 && rey < n)
            dfs(rex, rey);
        else
            continue;
    }
    return;
}

void dfs_all_search() {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] != 1) {
                dfs(i, j);
                counter++;
            } else
                continue;
        }
    }
    save.push_back(counter);
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (s > area[i][j])
                s = area[i][j];
            else if (b < area[i][j])
                b = area[i][j];
        }
    }
    for (int count = s; count < b; count++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] <= count)
                    visit[i][j] = 1;
                else
                    visit[i][j] = 0;
            }
        }
        dfs_all_search();
    }

    sort(save.begin(), save.end());
    cout << save[save.size() - 1] << endl;

    return 0;
}