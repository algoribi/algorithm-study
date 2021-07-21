#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0, visit[510], matchNum[510] = {0};
vector<int> graph[510];

int dfs(int n){
    for (int i : graph[n]) {
        if (!visit[i]) {
            visit[i] = 1;
            if (!matchNum[i] || dfs(matchNum[i])) {
                matchNum[i] = n;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            visit[j] = 0;
        ans += dfs(i);
    }
    
    cout << ans;

    return 0;
}