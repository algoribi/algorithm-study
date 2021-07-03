#include <iostream>
#define endl "\n"

using namespace std;

int n, map[105][105];
long long dp[105][105] = {0};

long long rec(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    if (x == n - 1 && y == n - 1)
        return 1;
    if (map[x][y] == 0)
        return dp[x][y] = 0;

    long long d1 = 0, d2 = 0;
    if (x + map[x][y] < n)
        d1 = rec(x + map[x][y], y);
    if (y + map[x][y] < n)
        d2 = rec(x, y + map[x][y]);
    return dp[x][y] = d1 + d2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << rec(0, 0);
    return 0;
}