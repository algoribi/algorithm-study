#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    pair<int, int> a, b;
    cin >> n >> a.first >> a.second >> b.first >> b.second;
    int dx[] = {-2, -2, 0, 0, 2, 2};
    int dy[] = {-1, 1, -2, 2, -1, 1};

    int map[200][200];
    int dist[200][200];
    queue<pair<int, int>> q;
    dist[a.first][a.second] = 1;
    q.push(a);
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int newx = front.first + dx[i];
            int newy = front.second + dy[i];
            if (0 <= newx && newx < n && 0 <= newy && newy < n && !dist[newx][newy]) {
                if (newx == b.first && newy == b.second) {
                    cout << dist[front.first][front.second];
                    return 0;
                }
                q.push({newx, newy});
                dist[newx][newy] = dist[front.first][front.second] + 1;
            }
        }
    }
    cout << -1;
    return 0;
}