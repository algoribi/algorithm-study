// algorithm study
// BOJ_1699_제곱수의 합

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[100010];
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        }
    }
    cout << dp[n];
    return 0;
}