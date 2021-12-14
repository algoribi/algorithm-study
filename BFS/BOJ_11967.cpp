#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, counter = 1, map[105][105], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1}; 
vector<pair<int,int>> v[105][105];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }

    queue<pair<int,int>> q;
    q.push({1, 1});
    map[1][1] = 2;

    while (!q.empty()){
        pair<int, int> f = q.front();
        q.pop();
        for (auto p : v[f.first][f.second]) {
            if (map[p.first][p.second])
                continue;
            for (int i = 0; i < 4; i++){
                int newx = p.first + dx[i];
                int newy = p.second + dy[i];
                if (map[newx][newy] == 2) {
                    q.push({newx, newy});
                    break;
                }
            }
            map[p.first][p.second] = 1;
            counter++;
        }

        for (int i = 0; i < 4; i++){
            int newx = f.first + dx[i];
            int newy = f.second + dy[i];
            if (map[newx][newy] == 1){
                map[newx][newy] = 2;
                q.push({newx,newy});
            }
        }
    }

    cout << counter;
    return 0;
}