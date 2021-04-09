#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> sol[32010];
    int chk[32010] = {0};
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        sol[a].push_back(b);
        chk[b]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (chk[i] == 0)
            pq.push(-i);
    }

    while (!pq.empty()) {
        int f = pq.top();
        pq.pop();
        cout << -f << ' ';
        for (int j = 0; j < sol[-f].size(); j++) {
            chk[sol[-f][j]]--;
            if (chk[sol[-f][j]] == 0)
                pq.push(-sol[-f][j]);
        }
    }
    return 0;
}