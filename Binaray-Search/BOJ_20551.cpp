#include <iostream>
#include <algorithm>
#include <set>

#define endl "\n"

using namespace std;

int n, m, t, arr[200005];
set<int> s;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    sort(arr, arr + n);
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (s.find(t) == s.end()) {
            cout << -1 << endl;
            continue;
        }
        int left = 0, right = n;
        while (right - left > 0) {
            int mid = (left + right) / 2;
            if (arr[mid] < t)
                left = mid + 1;
            else 
                right = mid;
        }
        cout << right << endl;
    }
    return 0;
}