// BOJ_11047_동전 0

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, k, a[13], count = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k >= a[i]) {
            count += k / a[i];
            k %= a[i];
        }
        if (k == 0)
            break;
    }

    cout << count;
    return 0;
}