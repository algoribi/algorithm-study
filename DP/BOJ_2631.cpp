// algorithm study
// BOJ_2631_줄세우기

#include <iostream>
using namespace std;

int main() {
    int n, max = 0, arr[210], dp[210];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (max < dp[i])
            max = dp[i];
    }

    cout << n - max;
    return 0;
}