// BOJ_11399_ATM

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> p;
    int n, add = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        p.push_back(num);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            add = add + p[j];
        }
    }

    cout << add << "\n";
    return 0;
}