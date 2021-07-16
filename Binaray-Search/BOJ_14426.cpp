#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;

    string s;
    vector<string> str;
    for (int i = 0; i < n; i++) {
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end());

    for (int i = 0; i < m; i++) {
        cin >> s;
        int left = 0, right = str.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (str[mid].substr(0, s.size()).compare(s) == 0) {
                ans++;
                break;
            }
            if (str[mid].compare(s) > 0)
                right = mid - 1;
            else if (str[mid].compare(s) < 0)
                left = mid + 1;
        }
    }
    cout << ans;

    return 0;
}