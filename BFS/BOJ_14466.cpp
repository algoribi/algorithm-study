#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, K, R, a, b, c, d, ans = 0, dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    bool map[105][105][5] = {0}, chk[105][105] = {0}; // map -> 0 : 왼, 1 : 오, 2 : 위, 3 : 아래, 4 : 소(cow)
    cin >> N >> K >> R;

    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c >> d;
        if (a == c && b > d) {
            map[a][b][0] = 1;
            map[c][d][1] = 1;
        } else if (a == c && b < d) {
            map[a][b][1] = 1;
            map[c][d][0] = 1;
        } else if (a > c && b == d) {
            map[a][b][2] = 1;
            map[c][d][3] = 1;
        } else {
            map[a][b][3] = 1;
            map[c][d][2] = 1;
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        map[a][b][4] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j][4] == 0 || chk[i][j] == 1)
                continue;
            int cow_counter = 1; // 자기 자신
            bool visit[105][105] = {0};
            visit[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                pair<int, int> f = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    if (map[f.first][f.second][i] == 1)
                        continue;
                    int newx = f.first + dx[i];
                    int newy = f.second + dy[i];
                    if (newx < 1 || newx > N || newy < 1 || newy > N || visit[newx][newy] == 1)
                        continue;
                    if (map[newx][newy][4] == 1) {
                        chk[newx][newy] = 1;
                        cow_counter++;
                    }
                    q.push({newx, newy});
                    visit[newx][newy] = 1;
                }
            }
            ans += (K - cow_counter) * cow_counter;
        }
    }
    cout << ans / 2;
    return 0;
}