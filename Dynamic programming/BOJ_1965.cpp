// algorithm study
// BOJ_1965_상자넣기

#include <iostream>

using namespace std;

int main() {
    int n, answer = 0, arr[1001], dp[1001];
    ;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        if (i == 0)
            continue;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] > answer)
            answer = dp[i];
    }

    cout << answer << '\n';
    return 0;
}