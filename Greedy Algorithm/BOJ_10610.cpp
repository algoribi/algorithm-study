// BOJ_10610_30

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int num[100010], add = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        num[i] = s[i] - '0';
        add += num[i];
    }
    sort(num, num + s.size());

    if (num[0] == 0 && add % 3 == 0) {
        for (int i = s.size() - 1; i >= 0; i--) {
            cout << num[i];
        }
    } else
        cout << -1;
    return 0;
}