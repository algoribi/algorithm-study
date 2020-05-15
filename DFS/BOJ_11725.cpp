// BOJ_11725_트리의 부모 찾기

#include <iostream>
#include <vector>

using namespace std;

vector<int> t[100001];
int ch[100001];
int chk[100001];

void dfs(int v) {
    chk[v] = 1;
    for (int i = 0; i < t[v].size(); i++) {
        if (chk[t[v][i]] == 0) {
            ch[t[v][i]] = v;
            dfs(t[v][i]);
        }
    }
}

int main() {
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << ch[i] << "\n";
    }
    return 0;
}
