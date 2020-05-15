// algorithm study
// BOJ_16947_서울 지하철 2호선

#include <iostream>
#include <vector>

using namespace std;

vector<int> sub[3005];
int n, f = 0, chk = 0, c = 0;
int visit[3005] = {0}, sub_l[3005] = {0};

void dfs_cycle(int n) {
    if (n == f && c > 2) {
        chk = 1;
        return;
    }
    if (visit[n] == 1)
        return;
    visit[n] = 1;
    for (int i = 0; i < sub[n].size(); i++) {
        c++;
        dfs_cycle(sub[n][i]);
        if (chk == 1)
            return;
        c--;
    }
    visit[n] = 0;
}

void dfs(int n, int b) {
    if (visit[n] == 1) {
        sub_l[f] = c;
        return;
    }
    for (int i = 0; i < sub[n].size(); i++) {
        if (sub[n][i] == b)
            continue;
        c++;
        dfs(sub[n][i], n);
        if (sub_l[f] > 0)
            return;
        c--;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sub[a].push_back(b);
        sub[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        f = i;
        c = 0;
        dfs_cycle(i);
        if (chk == 1)
            break;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 1)
            cout << 0 << " ";
        else {
            c = 0;
            f = i;
            dfs(i, i);
            cout << sub_l[i] << " ";
        }
    }
    return 0;
}