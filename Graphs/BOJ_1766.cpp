// BOJ_1766_문제집

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;
vector<int> go[32001];
int ind[32001];

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        go[u].push_back(v);
        ind[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0)
            pq.push(-i);
    }
    while (!pq.empty()) {
        int pl = pq.top();
        pq.pop();
        cout << -pl << ' ';
        for (int j = 0; j < go[-pl].size(); j++) {
            int num = go[-pl][j];
            ind[num]--;
            if (ind[num] == 0)
                pq.push(-num);
        }
    }
    return 0;
}