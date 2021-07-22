#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0, visit[1010], matchNum[1010] = {0};
vector<int> graph[1010];

int dfs(int num) {
    for (int i : graph[num]) {
        if (!visit[i]) {
            visit[i] = 1;
            if (!matchNum[i] || dfs(matchNum[i])) {
                matchNum[i] = num;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int num, a;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> a;
            graph[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) 
            visit[j] = 0;
        ans += dfs(i);
    }
    cout << ans;

    return 0;
}