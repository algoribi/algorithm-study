#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> plus, minus;
    int n, t, answer = 0, fl = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t <= 0)
            minus.push_back(t);
        else if (t > 0)
            plus.push_back(t);
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());
    for (int i = 1; i < plus.size(); i += 2) {
        if (plus[i] == 1 || plus[i - 1] == 1) {
            for (int j = i - 1; j < plus.size(); j++) {
                answer += plus[j];
            }
            fl = 1;
            break;
        }
        answer += plus[i] * plus[i - 1];
    }
    if (plus.size() % 2 == 1 && fl == 0)
        answer += plus[plus.size() - 1];
    for (int i = 1; i < minus.size(); i += 2) {
        answer += minus[i] * minus[i - 1];
    }
    if (minus.size() % 2 == 1)
        answer += minus[minus.size() - 1];
    cout << answer;
    return 0;
}