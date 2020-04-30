// BOJ_1931_회의실배정

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, count = 1;
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());

    int chk = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= chk) {
            count++;
            chk = v[i].first;
        }
    }

    cout << count << "\n";
    return 0;
}