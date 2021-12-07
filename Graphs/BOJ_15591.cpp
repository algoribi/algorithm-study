#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> moo[5005];
int mootube[5001][5001];

int counter(int k, int start) {
    int ans = 0;
    for (int i = 0; i < moo[start].size(); i++) {
        if (moo[start][i].second >= k)
            ans++;
    }
    return ans;
}

int main() {
    int n, q, a, b, c;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        moo[a].push_back({b, c}); 
        moo[b].push_back({a, c});
    }
    for (int i = 0; i < 5001; i++) {
        if (moo[i].size() == 0)
            continue;
        queue<pair<int, int>> q;
        bool visit[5001] = {0};
        q.push({i, -1});
        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            visit[f.first] = 1;
            for(int j = 0; j < moo[f.first].size(); j++) {
                if (visit[moo[f.first][j].first] == 1)
                    continue;
                if (f.second == -1) {
                    visit[moo[f.first][j].first] = 1;
                    q.push({moo[f.first][j].first, moo[f.first][j].second});
                } else {
                    q.push({moo[f.first][j].first, min(f.second, moo[f.first][j].second)});
                    mootube[i][moo[f.first][j].first] = min(f.second, moo[f.first][j].second);
                    mootube[moo[f.first][j].first][i] = min(f.second, moo[f.first][j].second);
                }
            }
        }
    }
    for (int i = 0; i < 5001; i++) {
        for (int j = 0; j < 5001; j++) {
            if (mootube[i][j] != 0)
                moo[i].push_back({j, mootube[i][j]});
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << counter(a, b) << "\n";
    }
    return 0;
}