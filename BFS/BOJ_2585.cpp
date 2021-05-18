#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cal(int a, int b, int c, int d) {
    return (int)ceil(sqrt((c - a) * (c - a) + (d - b) * (d - b)) / 10);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> pos;
    pos.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pos.push_back({a, b});
    }
    pos.push_back({10000, 10000});

    int left = 1, right = cal(0, 0, 10000, 10000);
    while (left <= right) {
        int mid = (left + right) / 2;
        queue<pair<int, int>> q;
        int visit[1010] = {0}, chk = 0;
        q.push({0, 0});
        visit[0] = 1;

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();

            if (f.first == pos.size() - 1) {
                if (f.second <= k + 1)
                    chk = 1;
                break;
            }

            for (int i = 0; i < pos.size(); i++) {
                if (visit[i] == 1)
                    continue;
                if (cal(pos[i].first, pos[i].second, pos[f.first].first, pos[f.first].second) <= mid) {
                    visit[i] = 1;
                    q.push({i, f.second + 1});
                }
            }
        }

        if (chk == 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left;
    return 0;
}