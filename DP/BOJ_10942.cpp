// algorithm study
// BOJ_10942_팰린드롬?

#include <iostream>
#include <vector>
using namespace std;

int n, f[2010][2010] = {0};
vector<int> num;

void same(int l, int r) {
    while (l >= 0 && r < n && num[r] == num[l]) {
        f[l][r] = 1;
        f[r][l] = 1;
        l--;
        r++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        num.push_back(t);
        f[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        int l = i - 1;
        int r = i + 1;
        same(l, r);
        l = i;
        r = i + 1;
        same(l, r);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << f[a - 1][b - 1] << "\n";
    }

    return 0;
}