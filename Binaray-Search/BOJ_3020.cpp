// algorithm study
// BOJ_3020_개똥벌레

#include <iostream>

using namespace std;

int main() {
    int n, h, t, c = 0, min = 200010;
    cin >> n >> h;
    int up[500010] = {0}, down[500010] = {0}, all[500010];
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (i % 2 != 0)
            up[h - t]++;
        else
            down[t - 1]++;
    }
    for (int i = h - 1; i > 0; i--) {
        down[i - 1] += down[i];
        up[h - i] += up[h - i - 1];
    }
    for (int i = 0; i < h; i++) {
        all[i] = up[i] + down[i];
        if (min > all[i]) {
            c = 1;
            min = all[i];
        } else if (min == all[i])
            c++;
    }
    cout << min << " " << c;
    return 0;
}