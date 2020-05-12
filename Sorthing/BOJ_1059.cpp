// algorithm study
// BOJ_1059_수2

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, num, n, min = 0, max = 0, answer = 0;
    cin >> l;
    vector<int> lucky;

    for (int i = 0; i < l; i++) {
        cin >> num;
        lucky.push_back(num);
    }
    sort(lucky.begin(), lucky.end());

    cin >> n;
    for (int i = 0; i < lucky.size(); i++) {
        if (lucky[i] == n) {
            cout << 0;
            return 0;
        } else if (lucky[i] < n) {
            if (lucky[i] > min)
                min = lucky[i];
        } else if (lucky[i] > n) {
            max = lucky[i];
            break;
        }
    }

    if (max == 0)
        max = 1001;
    for (int i = min + 1; i < max; i++) {
        if (i > n)
            continue;
        for (int j = i + 1; j < max; j++) {
            if (j < n)
                continue;
            answer++;
        }
    }

    cout << answer;
    return 0;
}