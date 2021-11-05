#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

vector<int> v[328010];
int visit[328010];

int main() {
    int n, s, p, a, b, counter = 0; // 블록 개수, 지지대 개수, 펭귄 위치
    cin >> n >> s >> p;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int, int>> q;
    q.push({p, 0});
    visit[p] = 1;

    while (!q.empty()) {
        int f1 = q.front().first;
        int f2 = q.front().second;
        q.pop();
        for (int i = 0; i < v[f1].size(); i++) {
            if (visit[v[f1][i]] == 1)
                continue;
            else 
                visit[v[f1][i]] = 1;
            if (v[f1][i] <= s) {
                if (counter != 0) {
                    counter += f2 + 1;
                    cout << n - counter - 1;
                    return 0;
                } else 
                    counter += f2 + 1;
            } else
                q.push({v[f1][i], f2 + 1});
        }
    }
}