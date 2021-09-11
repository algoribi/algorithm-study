#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    int n, t, ans = 0, counter = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        counter++;
        if (counter % 3 == 0)
            continue;
        ans += v[i];
    }
    cout <<ans;
}