#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a, b, c, counter = 0, map[15][15] = {0}, dx[] = {0, 0, 0, -1, 1}, dy[] = {0, 1, -1, 0, 0};
    pair<int, int> p[15];
    vector<pair<int, int>> num[15][15];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        p[i + 1] = {a, b};
        num[a][b].push_back({i + 1, c});
    }
    while (1) {
        if (counter > 1000) {
            cout << -1;
            return 0;
        }
        counter++;
        for (int i = 1; i <= k; i++) {
            pair<int, int> fl = p[i];
            if (num[fl.first][fl.second][0].first != i)
                continue;
            int newx = fl.first + dx[num[fl.first][fl.second][0].second];
            int newy = fl.second + dy[num[fl.first][fl.second][0].second];
            int size_num = num[fl.first][fl.second].size();
            if (newx <= 0 || newx > n || newy <= 0 || newy > n || map[newx][newy] == 2) { // 파란색
                if (num[fl.first][fl.second][0].second == 1)
                    num[fl.first][fl.second][0].second = 2;
                else if (num[fl.first][fl.second][0].second == 2)
                    num[fl.first][fl.second][0].second = 1;
                else if (num[fl.first][fl.second][0].second == 3)
                    num[fl.first][fl.second][0].second = 4;
                else 
                    num[fl.first][fl.second][0].second = 3;
                
                newx = fl.first + dx[num[fl.first][fl.second][0].second];
                newy = fl.second + dy[num[fl.first][fl.second][0].second];
                if (newx <= 0 || newx > n || newy <= 0 || newy > n || map[newx][newy] == 2)
                    continue;
            }
            
            if (map[newx][newy] == 0) { // 흰색
                for (int j = 0; j < size_num; j++) {
                    p[num[fl.first][fl.second][j].first].first = newx;
                    p[num[fl.first][fl.second][j].first].second = newy;
                    num[newx][newy].push_back(num[fl.first][fl.second][j]);
                }
                for (int j = 0; j < size_num; j++)
                    num[fl.first][fl.second].pop_back();
            } else if (map[newx][newy] == 1) { // 빨간색
                for (int j = 0; j < size_num; j++) {
                    p[num[fl.first][fl.second].back().first].first = newx;
                    p[num[fl.first][fl.second].back().first].second = newy;
                    num[newx][newy].push_back(num[fl.first][fl.second].back());
                    num[fl.first][fl.second].pop_back();
                }
            }

            if (num[newx][newy].size() >= 4) {
                cout << counter;
                return 0;
            }
        }
    }
}