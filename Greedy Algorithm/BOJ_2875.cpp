// BOJ_2875_대회 or 인턴

#include <iostream>

using namespace std;

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    while (n >= 2 && m >= 1) {
        ans++;
        n -= 2;
        m -= 1;
    }
    while (n + m < k) {
        ans--;
        n += 2;
        m += 1;
    }
    cout << ans;
    return 0;
}