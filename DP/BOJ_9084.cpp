// algorithm study
// BOJ_9084_동전

#include <iostream>
using namespace std;

int main() {
    int t, dp[10001], coin[21];
    cin >> t;
    while (t != 0) {
        for (int i = 0; i <= 10000; i++) {
            dp[i] = 0;
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        int max;
        cin >> max;
        for (int i = 0; i < n; i++) {
            dp[coin[i]]++;
            for (int j = coin[i] + 1; j <= max; j++) {
                dp[j] = dp[j] + dp[j - coin[i]];
            }
        }
        cout << dp[max] << '\n';
        t--;
    }
    return 0;
}