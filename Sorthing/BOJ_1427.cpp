// BOJ_1427_소트인사이드

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    vector<char> v;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        v.push_back('0');
        v[i] = s[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    return 0;
}