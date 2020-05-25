// BOJ_1766_문제집

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;
vector<int> graph[32001];
int sum[32001];

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        sum[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] == 0)
            pq.push(-i);
    }
    while (!pq.empty()) {
        int pl = pq.top();
        pq.pop();
        cout << -pl << ' ';
        for (int j = 0; j < graph[-pl].size(); j++) {
            int num = graph[-pl][j];
            sum[num]--;
            if (sum[num] == 0)
                pq.push(-num);
        }
    }
    return 0;
}