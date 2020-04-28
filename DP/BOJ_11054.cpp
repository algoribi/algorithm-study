// algorithm study
// BOJ_11054_가장 긴 바이토닉 부분 수열

#include <iostream>
using namespace std;

int main() {
    int arr[1001], dp1[1001], dp2[1001], ans[1001];
    int n, maxx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp1[i] <= dp1[j])
                dp1[i] = dp1[j] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        dp2[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i] && dp2[i] <= dp2[j])
                dp2[i] = dp2[j] + 1;
        }
    }
    for (int l = 0; l < n; l++) {
        ans[l] = dp1[l] + dp2[l];
        if (ans[l] > maxx)
            maxx = ans[l];
    }

    cout << maxx - 1 << '\n';
    return 0;
}