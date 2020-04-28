// algorithm study
// BOJ_9095_1,2,3 더하기

#include <iostream>

using namespace std;

#define endl "\n"

int main() {
    int t, dp[20];
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 15; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}