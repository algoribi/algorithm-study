// BOJ_2437_저울

#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(void) {
    int n, w, add = 1;
    cin >> n;
    vector<int> weight;

    for (int i = 0; i < n; i++) {
        cin >> w;
        weight.push_back(w);
    }

    sort(weight.begin(), weight.end());

    if (weight[0] != 1) {
        cout << "1" << endl;
        return 0;
    }

    for (int j = 1; j < n; j++) {
        if (weight[j] > add + 1) {
            cout << add + 1 << endl;
            return 0;
        } else
            add = add + weight[j];
    }
    cout << add + 1 << endl;

    return 0;
}