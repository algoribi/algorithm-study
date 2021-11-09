#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

struct p {
    int num, minute, taxi;
};

int n, t, m, ans = 10001, visit[101];
vector<p> map[101];

void dfs(int point, int time, int money) {
    if (time > t || money > m)
        return;
    if (point == n && money < ans) {
        ans = money;
        return;
    }
    for (int i = 0; i < map[point].size(); i++) {
        if (visit[map[point][i].num] == 1) 
            continue;
        visit[map[point][i].num] = 1;
        dfs(map[point][i].num, time + map[point][i].minute, money + map[point][i].taxi);
        visit[map[point][i].num] = 0;
    }
}

int main() {

    ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    int l, a, b, c, d;
    cin >> n >> t >> m >> l;
    for (int i = 0; i < l; i++) {
        cin >> a >> b >> c >> d;
        map[a].push_back({b, c, d});
        map[b].push_back({a, c, d});
    }
    visit[1] = 1;
    dfs(1, 0, 0);
    if (ans != 10001)
        cout << ans;
    else 
        cout << -1;
    return 0;
}