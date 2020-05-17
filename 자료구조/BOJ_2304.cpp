// algorithm study
// BOJ_2304_창고 다각형

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool p_sort(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.first;
    return a.first < b.first;
}

int main() {
    int n, max_h = 0, max_x = 0, answer = 0;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), p_sort);
    for (int i = 0; i < n; i++) {
        if (arr[i].second >= max_h) {
            answer += (arr[i].first - max_x) * max_h;
            max_x = arr[i].first;
            max_h = arr[i].second;
        }
    }
    answer += max_h;
    int savex = max_x;
    max_h = max_x = 0;
    for (int i = n - 1; arr[i].first > savex; i--) {
        if (arr[i].second > max_h) {
            answer += (max_x - arr[i].first) * max_h;
            max_x = arr[i].first;
            max_h = arr[i].second;
        }
    }
    answer += (max_x - savex) * max_h;
    cout << answer;
    return 0;
}