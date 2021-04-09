#include <iostream>
#include <vector>

using namespace std;

vector<long long> time;

int main() {
    long long n, m, t, max_time = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        time.push_back(t);
        if (t > max_time)
            max_time = t;
    }

    long long minn = 1, maxn = m * max_time, ans = m * max_time;

    while (minn < maxn) {
        long long mid = (minn + maxn) / 2, counter = 0;

        for (int i = 0; i < time.size(); i++)
            counter += mid / time[i];

        if (m <= counter) {
            if (ans > mid)
                ans = mid;
            maxn = mid;
        } else
            minn = mid + 1;
    }
    cout << ans;

    return 0;
}