// algorithm study
// BOJ_11053_가장 긴 증가하는 부분 수열

#include <iostream>
using namespace std;

int main() {
    int arr[1001], dp[1001];
    int n, answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
        if (answer < dp[i])
            answer = dp[i];
    }

    cout << answer << '\n';
    return 0;
}