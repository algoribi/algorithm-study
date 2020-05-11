// BOJ_1967_트리의 지름

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > t[10001];
int save_p, b_save, save_l, p;

void dfs(int v, int parent) {
    if (v == p) {
        save_l = 0;
        b_save = 0;
    }
    if (b_save < save_l) {
        b_save = save_l;
        save_p = v;
    }
    for (int i = 0; i < t[v].size(); i++) {
        int nxt = t[v][i].first;
        if (nxt == parent)
            continue;
        save_l = save_l + t[v][i].second;
        dfs(nxt, v);
        save_l = save_l - t[v][i].second;
    }
    return;
}

int main() {
    int n, a, b, c;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        t[a].push_back(make_pair(b, c));
        t[b].push_back(make_pair(a, c));
    }
    p = 1;
    dfs(1, -1);
    p = save_p;
    dfs(save_p, -1);
    cout << b_save << '\n';

    return 0;
}