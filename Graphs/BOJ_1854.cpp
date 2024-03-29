#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int n, m, k, from, to, cost, Start;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
priority_queue<int> heap[1001];
vector<pair<int, int> > v[1001];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }
 
    pq.push(make_pair(0, 1));
    heap[1].push(0);
    
    while(!pq.empty()) {
        int x = pq.top().second;
        int num = pq.top().first;
        pq.pop();
    
        for(int i = 0; i < v[x].size(); i++) {
            int next = v[x][i].first;
            int cost = num+v[x][i].second;
            if (heap[next].size()<k) {
                heap[next].push(cost);
                pq.push(make_pair(cost, next));
            } else {
                if (heap[next].top()>cost) {
                    heap[next].pop();
                    heap[next].push(cost);
                    pq.push(make_pair(cost, next));
                }
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        // 1번 도시에서 i번 도시까지의 k번째 최단 경로
        if (heap[i].size()<k)
            cout << "-1" << "\n";
        else
            cout << heap[i].top() << "\n";
    }
 
    return 0;
}