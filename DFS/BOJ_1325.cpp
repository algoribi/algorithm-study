// BOJ_1325_효율적인 해킹

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10001];
int n, m, chk[10001], chk_dfs[10001], in, co, maxx = 0;

int dfs(int num) {
    int ret = 1;
    chk_dfs[num] = 1;
    for (int i = 0; i < v[num].size(); i++) {
        int nxt = v[num][i];
        if (chk_dfs[nxt] != 1) {
            ret += dfs(nxt);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        chk[i] = dfs(i);
        maxx = max(maxx, chk[i]);
        for (int j = 1; j <= n; j++) {
            chk_dfs[j] = 0;
        }
    }
    for (int j = 1; j <= n; j++) {
        if (chk[j] == maxx)
            cout << j << " ";
    }
    cout << '\n';
    return 0;
}