// BOJ_1012_유기농 배추

#include <stdio.h>

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int t, m, n, k, arr[52][52];
vector<int> ans;

bool dfs(int x, int y) {
    if (arr[x][y] == 2)
        return false;
    if (arr[x][y] == 0)
        return false;
    arr[x][y] = 2;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
    return true;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int tmpans = 0;
        vector<pair<int, int>> v;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x + 1, y + 1));
            arr[x + 1][y + 1] = 1;
        }
        for (int j = 0; j < k; j++) {
            if (dfs(v[j].first, v[j].second))
                tmpans++;
        }
        ans.push_back(tmpans);

        memset(arr, 0, sizeof(arr));
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", ans[i]);
}