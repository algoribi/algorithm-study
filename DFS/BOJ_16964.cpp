// algorithm study
// BOJ_16964_DFS 스페셜 저지

#include <iostream>
#include <vector>

using namespace std;

bool check[100010];
vector<int> v[100010], an;
int n, c = 0, answer = 0;

void dfs(int x) {
    if (c == n - 1) {
        answer = 1;
        return;
    }
    check[x] = true;
    for (int y = 0; y < v[x].size();) {
        if (check[v[x][y]] == false && an[c + 1] == v[x][y]) {
            c++;
            dfs(v[x][y]);
            y = 0;
        } else
            y++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        an.push_back(t);
    }
    if (an[0] != 1)
        answer = 0;
    dfs(1);
    cout << answer;

    return 0;
}