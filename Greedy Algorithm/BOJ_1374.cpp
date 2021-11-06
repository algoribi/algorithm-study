#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define endl "\n"

using namespace std;

int main() {
    int n, ans = 0, a, b, c;
    vector<pair<int, int>> v;
    multiset<int> s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (s.size() == 0 || *s.begin() > v[i].first) {
            s.insert(v[i].second);
        } else {
            s.erase(s.begin());
            s.insert(v[i].second);
        }

        if (s.size() > ans)
            ans = s.size();
    }
    
    cout << ans;

    return 0;
}