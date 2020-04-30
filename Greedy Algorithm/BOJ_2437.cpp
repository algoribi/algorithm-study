// BOJ_2437_저울

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> weight;
    int n, add = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        weight.push_back(w);
    }
    sort(weight.begin(), weight.end());

    if (weight[0] != 1) {
        cout << 1;
        return 0;
    }

    for (int j = 1; j < n; j++) {
        if (weight[j] > add + 1) {
            cout << add + 1;
            return 0;
        } else
            add += weight[j];
    }
    cout << add + 1;

    return 0;
}