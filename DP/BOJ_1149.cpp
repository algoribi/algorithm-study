// algorithm study
// BOJ_1149_RGB거리

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, cost[1010][3], dp[1010][3];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        //cin r, g, b
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int an = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << an << '\n';
    return 0;
}