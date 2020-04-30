// algorithm study
// BOJ_11726_2xn 타일링

#include <iostream>

using namespace std;

int main() {
    int n, dp[1010];
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];
    return 0;
}